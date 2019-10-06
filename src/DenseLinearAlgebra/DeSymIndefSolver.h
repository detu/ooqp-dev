/* OOQP                                                               *
 * Authors: E. Michael Gertz, Stephen J. Wright                       *
 * (C) 2001 University of Chicago. See Copyright Notification in OOQP */

#pragma once

#include "DenseStorageHandle.h"
#include "DenseSymMatrixHandle.h"
#include "src/Abstract/DoubleLinearSolver.h"
#include "src/Vector/SimpleVectorHandle.h"

/** A linear solver for dense, symmetric indefinite systems
 * @ingroup DenseLinearAlgebra
 * @ingroup LinearSolvers
 */
class DeSymIndefSolver : public DoubleLinearSolver
{
public:
	DenseStorageHandle mStorage;

protected:
	SimpleVectorHandle work;
	int*               ipiv;

public:
	DeSymIndefSolver(DenseSymMatrix* storage);
	virtual void diagonalChanged(int idiag, int extent);
	virtual void matrixChanged();
	virtual void solve(OoqpVector& vec);
	virtual ~DeSymIndefSolver();
};
