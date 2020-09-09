// @filename: Test.cpp
// @author: Alex Banning (abanning)
// @assignment: Assignment 2 - Exceptions and Operator Overloading for Priority Queue
// @date: February 8th, 2019
// @description: Header file for QueueA.cpp. Declares methods and data members of
//				 object Queue.

#include "QueueException.h"
#ifndef QUEUEA_H
#define QUEUEA_H
//const int MAX_QUEUE = maximum-size-of-queue;
//typedef desired-type-of-queue-item QueueItemType;
const int MAX_QUEUE = 15;
typedef int QueueItemType;

/** @class Queue
 * ADT queue - Array-based implementation. */
class Queue
{
	friend ostream& operator<<(ostream& output, const Queue& q);
	friend void display(const Queue& q1);
	
public:
// constructors and destructor:
	/** Default constructor. */
	Queue();
	// copy constructor and destructor are
	// supplied by the compiler

// Queue operations:
	bool isEmpty() const;
	virtual void enqueue(const QueueItemType& newItem) throw (QueueException);
	void dequeue(QueueItemType& queueFront) throw (QueueException);
	void getFront(QueueItemType& queueFront) const throw (QueueException);
	int getCount() const;
	bool operator<(const Queue &q2); 
	void resetQueue();


protected:
	QueueItemType items[MAX_QUEUE];
	int           front;
	int           back;
	int           count;
}; // end Queue

// Non-member function declaration
	bool operator> (const Queue& q1, const Queue& q2);

#endif
// End of header file.
