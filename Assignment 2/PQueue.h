// @filename: Test.cpp
// @author: Alex Banning (abanning)
// @assignment: Assignment 2 - Exceptions and Operator Overloading for Priority Queue
// @date: February 8th, 2019
// @description: header file for PQueue.cpp. Declares methods and data members of
//				 object PriorityQueue

#include "QueueException.h"
#include "QueueA.h"

#ifndef PRIORITYQUEUEA_H
#define PRIORITYQUEUEA_H


class PriorityQueue: public Queue
{
public:
// constructors and destructor:
	/** Default constructor. */
	PriorityQueue();

	void enqueue(const QueueItemType& newItem) throw (QueueException);

};	// end PriorityQueue
#endif
// End of header file.
