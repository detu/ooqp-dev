/* OOQP                                                               *
 * Authors: E. Michael Gertz, Stephen J. Wright                       *
 * (C) 2001 University of Chicago. See Copyright Notification in OOQP */

#pragma once

#include "IotrRefCount.h"
#include "SmartPointer.h"

class SparseSymMatrix;
typedef SmartPointer<SparseSymMatrix> SparseSymMatrixHandle;
//using SparseSymMatrixHandle = SmartPointer<SparseSymMatrix>;
