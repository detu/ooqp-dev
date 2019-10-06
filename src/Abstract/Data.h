/* OOQP                                                               *
 * Authors: E. Michael Gertz, Stephen J. Wright                       *
 * (C) 2001 University of Chicago. See Copyright Notification in OOQP */
#pragma once

class Variables;

class Data
{
public:
	Data();
	virtual ~Data();

	virtual double datanorm() = 0;

	virtual void print() = 0;
};
