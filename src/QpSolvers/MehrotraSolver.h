/* OOQP                                                               *
 * Authors: E. Michael Gertz, Stephen J. Wright                       *
 * (C) 2001 University of Chicago. See Copyright Notification in OOQP */

#pragma once

#include "src/Abstract/OoqpMonitor.h"
#include "src/Abstract/Solver.h"

class Data;
class Variables;
class ProblemFormulation;

/** Derived class of Solver implementing the original Mehrotra
 *  predictor-corrector algorithm
 * @ingroup QpSolvers
 */
class MehrotraSolver : public Solver
{
protected:
	ProblemFormulation* factory;

	/** parameter in range [0,100] determines verbosity. (Higher value
	 *  => more verbose.) */
	int printlevel;

	/** exponent in Mehrotra's centering parameter, which is usually
	 *  chosen to me (muaff/mu)^tsig, where muaff is the predicted
	 *  complementarity gap obtained from an affine-scaling step, while
	 *  mu is the current complementarity gap */
	double tsig;

	/**  storage for step vectors */
	Variables* step;

public:
	MehrotraSolver(ProblemFormulation* opt, Data* prob);

	~MehrotraSolver();

	virtual int solve(Data* prob, Variables* iterate, Residuals* resids);

	virtual void defaultMonitor(Data*      data,
	                            Variables* vars,
	                            Residuals* resids,
	                            double     alpha,
	                            double     sigma,
	                            int        i,
	                            double     mu,
	                            int        status_code,
	                            int        level);
};
