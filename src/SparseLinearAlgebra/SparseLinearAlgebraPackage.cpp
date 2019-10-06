/* OOQP                                                               *
 * Authors: E. Michael Gertz, Stephen J. Wright                       *
 * (C) 2001 University of Chicago. See Copyright Notification in OOQP */

#include "SparseGenMatrix.h"
#include "SparseLinearAlgebraPackage.h"
#include "SparseSymMatrix.h"
#include "src/Abstract/DoubleMatrix.h"
#include "src/Vector/SimpleVector.h"

SparseLinearAlgebraPackage* SparseLinearAlgebraPackage::soleInstance()
{
	static SparseLinearAlgebraPackage* la = 0;

	if (!la)
		la = new SparseLinearAlgebraPackage;

	return la;
}

SymMatrix* SparseLinearAlgebraPackage::newSymMatrix(int size, int nnz)
{
	return new SparseSymMatrix(size, nnz);
}

GenMatrix* SparseLinearAlgebraPackage::newGenMatrix(int m, int n, int nnz)
{
	return new SparseGenMatrix(m, n, nnz);
}

OoqpVector* SparseLinearAlgebraPackage::newVector(int n)
{
	return new SimpleVector(n);
}
