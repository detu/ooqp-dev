/* OOQP                                                               *
 * Authors: E. Michael Gertz, Stephen J. Wright                       *
 * (C) 2001 University of Chicago. See Copyright Notification in OOQP */

#include "QpGenSparseMa27.h"
#include "Ma27Solver.h"
#include "QpGenData.h"
#include "QpGenSparseLinsys.h"
#include "SimpleVector.h"
#include "SimpleVectorHandle.h"
#include "SparseLinearAlgebraPackage.h"
#include "SparseSymMatrix.h"
#include <memory>

QpGenSparseMa27::QpGenSparseMa27(int nx_in,
                                 int my_in,
                                 int mz_in,
                                 int nnzQ_in,
                                 int nnzA_in,
                                 int nnzC_in)
    : QpGenSparseSeq(nx_in, my_in, mz_in, nnzQ_in, nnzA_in, nnzC_in)
{
	la = SparseLinearAlgebraPackage::soleInstance();
}

LinearSystem* QpGenSparseMa27::makeLinsys(Data* prob_in)
{
	QpGenData* prob = (QpGenData*)prob_in;

	// QpGenData(LinearAlgebraPackage* la, int nx_, int my_, int mz_, int nnzQ, int nnzA, int nnzC);
	//auto prob = std::make_unique<QpGenData>(la,nx,my,mz, nnzQ, nnzA, nnzC);

	int        n    = nx + my + mz;

	SparseSymMatrixHandle Mat(new SparseSymMatrix(n, n + nnzQ + nnzA + nnzC));

	SimpleVectorHandle v(new SimpleVector(n));
	v->setToZero();
	Mat->setToDiagonal(*v);

	prob->putQIntoAt(*Mat, 0, 0);
	prob->putAIntoAt(*Mat, nx, 0);
	prob->putCIntoAt(*Mat, nx + my, 0);

	Ma27Solver* solver = new Ma27Solver(Mat);
	//auto solver = std::make_unique<Ma27Solver>(Mat);

	return new QpGenSparseLinsys(this, prob, la, Mat, solver);
}
