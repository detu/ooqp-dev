/* OOQP                                                               *
 * Authors: E. Michael Gertz, Stephen J. Wright                       *
 * (C) 2001 University of Chicago. See Copyright Notification in OOQP */

#pragma once

#include "src/Abstract/LinearAlgebraPackage.h"

#include "src/Abstract/DoubleMatrixHandle.h"
#include "src/Vector/OoqpVectorHandle.h"

class DoubleLinearSolver;

/**
 * @defgroup DenseLinearAlgebra
 *
 * A module for sparse linear operators and equations
 * @{
 */

/**
 * Creates dense matrices and SimpleVectors.
 *
 * Singleton class. Only accessible through
 * SparseLinearAlgebraPackage::soleInstance
 */
class DenseLinearAlgebraPackage : public LinearAlgebraPackage
{
protected:
	DenseLinearAlgebraPackage() {}
	virtual ~DenseLinearAlgebraPackage() {}

public:
	/** Return the sole instance of this class. This instance must not
	 * ever be deleted. */
	static DenseLinearAlgebraPackage* soleInstance();
	virtual SymMatrix*                newSymMatrix(int size, int nnz);
	virtual GenMatrix*                newGenMatrix(int m, int n, int nnz);
	virtual OoqpVector*               newVector(int n);
};

/**
 * @}
 */
