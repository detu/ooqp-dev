/* OOQP                                                               *
 * Authors: E. Michael Gertz, Stephen J. Wright                       *
 * (C) 2001 University of Chicago. See Copyright Notification in OOQP */

#include "VectorUtilities.h"
#include <cstring>

void set_to_zero(double v[], int n, int stride)
{
	int i;
	int lenv = stride * n;
	for (i = 0; i < lenv; i += stride)
		v[i] = 0;
}

void writef_to_stream(double v[], int n, int stride, std::ostream& out, const char format[])
{
	int i;
	int lenv = n * stride;

	for (i = 0; i < lenv; i += stride)
	{
		int  j = 0;
		char c;
		while ((c = format[j]) != 0)
		{
			if (c != '%')
			{
				out << c;
			}
			else
			{
				// Brain-dead variable substitution, but good enough for this
				// simple case
				if (0 == strncmp("{value}", &format[j + 1], 7))
				{
					out << v[i];
					j += 7;
				}
				else if (0 == strncmp("{index}", &format[j + 1], 7))
				{
					out << i;
					j += 7;
				}
				else
				{
					out << c;
				}
			}
			j++;
		}
		out << std::endl;
	}
}

void set_to_constant(double v[], int n, int stride, double c)
{
	int i;
	int lenv = n * stride;
	for (i = 0; i < lenv; i += stride)
		v[i] = c;
}

void add_constant(double v[], int n, int stride, double c)
{
	int i;
	int lenv = n * stride;
	for (i = 0; i < lenv; i += stride)
		v[i] += c;
}

double stepbound(double v[], int n, int incv, double s[], int incs, double max)
{
	double  bound = max;
	double* pv    = v;
	double *ps = s, *lasts = s + n * incs;
	for (; ps < lasts; ps += incs, pv += incv)
	{
		double ss = *ps;
		if (ss < 0)
		{
			double cbnd = -*pv / ss;
			if (cbnd < bound)
				bound = cbnd;
		}
	}
	return bound;
}

double stepbound(double v[],
                 int    n,
                 int    incv,
                 double s[],
                 int    incs,
                 double b[],
                 int    incb,
                 double u[],
                 int    incu,
                 double max)
{
	double  bound = max;
	double* pv    = v;
	double *ps = s, *lasts = s + n * incs;
	int     i;
	for (i = 0; ps < lasts; ps += incs, pv += incv, i++)
	{
		double ss = *ps;
		double cbnd;
		if (ss > 0)
		{
			cbnd = (u[i * incu] - *pv) / ss;
		}
		else if (ss < 0)
		{
			cbnd = (b[i * incb] - *pv) / ss;
		}
		else
		{
			continue;  // Next element
		}
		if (cbnd < bound)
			bound = cbnd;
	}
	return bound;
}

void axdzpy(int n, double alpha, double x[], int incx, double z[], int incz, double y[], int incy)
{
	double *px = x, *py = y, *pz = z, *lastx = x + incx * n;
	for (; px < lastx; px += incx, py += incy, pz += incz)
	{
		*py += alpha * (*px / *pz);
	}
}

double find_blocking(double  w[],
                     int     n,
                     int     incw,
                     double  wstep[],
                     int     incwstep,
                     double  u[],
                     int     incu,
                     double  ustep[],
                     int     incustep,
                     double  maxStep,
                     double* w_elt,
                     double* wstep_elt,
                     double* u_elt,
                     double* ustep_elt,
                     int&    first_or_second)
{
	double bound = maxStep;

	int i = n - 1, lastBlocking = -1;

	// Search backward so that we find the blocking constraint of lowest
	// index. We do this to make things consistent with MPI's MPI_MINLOC,
	// which returns the processor with smallest rank where a min occurs.
	//
	// Still, going backward is ugly!
	double* pw     = w + (n - 1) * incw;
	double* pwstep = wstep + (n - 1) * incwstep;
	double* pu     = u + (n - 1) * incu;
	double* pustep = ustep + (n - 1) * incustep;

	while (i >= 0)
	{
		double temp = *pwstep;
		if (*pw > 0 && temp < 0)
		{
			temp = -*pw / temp;
			if (temp <= bound)
			{
				bound           = temp;
				lastBlocking    = i;
				first_or_second = 1;
			}
		}
		temp = *pustep;
		if (*pu > 0 && temp < 0)
		{
			temp = -*pu / temp;
			if (temp <= bound)
			{
				bound           = temp;
				lastBlocking    = i;
				first_or_second = 2;
			}
		}

		i--;
		if (i >= 0)
		{
			// It is safe to decrement the pointers
			pw -= incw;
			pwstep -= incwstep;
			pu -= incu;
			pustep -= incustep;
		}
	}

	if (lastBlocking > -1)
	{
		// fill out the elements
		*w_elt     = w[lastBlocking];
		*wstep_elt = wstep[lastBlocking];
		*u_elt     = u[lastBlocking];
		*ustep_elt = ustep[lastBlocking];
	}
	return bound;
}
/* OOQP                                                               *
 * Authors: E. Michael Gertz, Stephen J. Wright                       *
 * (C) 2001 University of Chicago. See Copyright Notification in OOQP */

#ifndef IOTRREFCOUNT
#define IOTRREFCOUNT

/** @defgroup ReferenceCounting
 * Code to support reference-count garbage collection.
 * @{
 */

/**
 * @file IotrRefCount.h
 *
 * A module supporting reference-count garbage collection.
 **/

#include <cassert>

/**
 * A base class for classes that support reference-count
 * garbage collection.
 **/
class IotrRefCount
{
public:
	/** The number of instances of IotrRefCount. This is useful for
	 *  debugging purposes. If not zero when the program exits, you
	 *  have a memory leak. */
	static int instances;

	/** The number of references to this object. */
	int refs() { return mRefs; };

	/** Release this reference to obj: it is more convenient to call the
	 * template function IotrRelease().  The parameter obj contains the
	 * address of a pointer of type exactly (IotrRefCount *). In other
	 * words it can't be a pointer to an instance of a
	 * subclass. IotrRelease() does not have this restriction.  @see
	 * IotrRelease. */
	static inline void release(IotrRefCount** obj);

	/** Increment the reference count of this object: it is more
	 *  convenient to call the template function IotrAddRef().  The
	 *  parameter obj contains the address of a pointer of type exactly
	 *  (IotrRefCount *). In other words it can't be a pointer to an
	 *  instance of a subclass. IotrAddRef() does not have this
	 *  restriction. @see IotrAddRef */
	static inline void addRef(IotrRefCount* const* obj);

	/** Default constructor. Creates an instance with one reference */
	IotrRefCount() : mRefs(1) { instances++; };

protected:
	/** Protected virtual destructor. One should not call delete on
	 *  reference-counted objects.
	 **/
	virtual ~IotrRefCount() { instances--; };

private:
	/** The number of (hard) references to this object */
	int mRefs;
	/** Operator =. Makes sure that even though all other variables are
	 *  copied, the reference count is not! In general, IotrRefCount objects
	 *  should not be copied this way, which is why this operator is private.
	 */
	// cppcheck-suppress operatorEqVarError
	IotrRefCount& operator=(const IotrRefCount&)
	{
		// mRefs = mRefs;
		return *this;
	}
	/** Copy constructor. Make sure the reference count for the new object
	 *  equals one. In general, IotrRefCount objects should not be copied
	 *  this way, which is why this constructor is private. */
	IotrRefCount(const IotrRefCount&)
	{
		instances++;
		mRefs = 1;
	}
};

inline void IotrRefCount::release(IotrRefCount** obj)
{
	assert(!*obj || (*obj)->mRefs > 0);
	if (*obj && 0 >= --(*obj)->mRefs)
		delete *obj;
	*obj = 0;
}

inline void IotrRefCount::addRef(IotrRefCount* const* obj)
{
	assert(!*obj || (*obj)->mRefs > 0);
	if (*obj)
		(*obj)->mRefs++;
}

/** Release a reference to an object.  If the number of references to
 * obj becomes zero, delete the object.
 *
 * @param obj the address of a pointer to the object to be
 * released. On exit, this pointer (*obj) will be set to nil.
 * */
template <class T>
inline void IotrRelease(T** obj)
{
	IotrRefCount* objref = *obj;
	IotrRefCount::release(&objref);

	*obj = (T*)objref;
}

/** Increments the reference count of obj.  Objects are only deleted
 * when their reference count becomes zero, so this call must be
 * balanced by a call to IotrRelease to decrement the reference count
 * when this object is no longer needed.
 *
 * @param obj the address of a pointer to the object whose reference count is
 * to be incremented. The pointer (*obj) will be unaltered.
 * @see IotrRelease */
template <class T>
inline void IotrAddRef(T* const* obj)
{
	IotrRefCount* objref = *obj;
	IotrRefCount::addRef(&objref);
}

/**
 * @}
 */
#endif
