/* OOQP                                                               *
 * Authors: E. Michael Gertz, Stephen J. Wright                       *
 * (C) 2001 University of Chicago. See Copyright Notification in OOQP */

#include "QpBound.h"
#include "QpBoundData.h"
#include "QpBoundResiduals.h"
#include "QpBoundVars.h"
#include "src/Abstract/DoubleMatrix.h"
#include "src/Abstract/LinearAlgebraPackage.h"
#include "src/Vector/OoqpVector.h"

QpBound::QpBound(int nx_) : la(0)
{
	nx = nx_;
}

Data* QpBound::makeRandomData()
{
	SymMatrixHandle Q(la->newSymMatrix(nx, nx * nx));
	QpBoundData*    data = new QpBoundData(this, Q, nx);
	data->datarandom();

	return data;
}

Residuals* QpBound::makeResiduals(Data* problem)
{
	return new QpBoundResiduals(this, (QpBoundData*)problem, nx);
}

Variables* QpBound::makeVariables(Data* problem)
{
	return new QpBoundVars(this, (QpBoundData*)problem);
}

OoqpVector* QpBound::newPrimalVector()
{
	return la->newVector(nx);
}

QpBound::~QpBound() {}
