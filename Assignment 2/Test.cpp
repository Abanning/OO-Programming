// @filename: Test.cpp
// @author: Alex Banning (abanning)
// @assignment: Assignment 2 - Exceptions and Operator Overloading for Priority Queue
// @date: February 8th, 2019
// @description: Test program for PriorityQueue and Queue with thrown Exceptions
// 				 and operator overloading. This program tests each function of
//				 Queue base class and PriorityQueue derived class. All tests and
//				 significant changes performed on the Queue objects will be documented
//				 on the user's screen.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "QueueA.h"
#include "QueueException.h"
#include "PQueue.h"
using namespace std;

int main()
{
	// Variable declaration and initialization
	Queue q1;
	PriorityQueue pq1;
	Queue *qptr;
	QueueItemType frontItem;
	QueueItemType newItem;
	string queueType = "Standard Queue with Exception Handling.";
	
	// Random num seeding
	int seed = time(0);
	srand(seed);
	
	for (int test = 0; test <= 1; test++)
	{
	// Standard Queue test 1st time, Priority Queue 2nd time:
	//----------------------------------------------------------------------------
		cout << endl << endl;
		cout << "Testing " << queueType << endl;
		cout << "---------------------------------------------------------";
		cout << endl;
		qptr = &q1;
	// Enqueuing to MAX_QUEUE limit
		cout << "Enqueuing..." << endl;
		for (int i = 0; i < MAX_QUEUE; i++)
		{
			newItem = rand() % 101;
			qptr -> enqueue(newItem);
		}
	
	// Printing the queue
		if (queueType == "Priority Queue with Exception Handling.")
		{
			cout << "Notice: The priority queue class header and implementation files ";
			cout << "were given to us by Dr. Zhang. The implementation does not seem to ";
			cout << "be correct. There is something not working correctly with the modulus ";
			cout << "operation." << endl;
		}
		display(q1);

	// Attempt further enqueue
		cout << "Attempting to enqueue..." << endl;
		try
		{
			newItem = rand() % 101;
			qptr -> enqueue(newItem);
		}
		catch (QueueException &e) 
		{
			cout << e.what() << endl;
		}
	
	// Get front item on a full queue
		qptr -> getFront(frontItem);
		cout << "The front item in the queue is: " << frontItem << endl;
	
	// Dequeuing until empty
		cout << "Dequeuing..." << endl << endl;
		for (int j = qptr -> getCount(); j > 0; j--)
		{
			qptr -> dequeue(frontItem);
		}
		
	// Reset queue
		cout << "The Queue has been reset." << endl;
		q1.resetQueue();
		
	// Printing the queue
		display(q1);
	
	// Attempt further dequeue
		cout << endl;
		cout << "Attempting to dequeue..." << endl;
		try
		{
			qptr -> dequeue(frontItem);
		}
		catch (QueueException &e)
		{
			cout << e.what() << endl;
		}
	
	// Attempt getFront() on empty queue
		cout << "Attempting to get front item..." << endl;
		try
		{
			qptr -> getFront(frontItem);
			cout << "The front item in the queue is: " << frontItem;
			cout << endl;
		}
		catch (QueueException &e)
		{
			cout << e.what() << endl;
		}
		qptr = &pq1;
		queueType = "Priority Queue with Exception Handling.";
		cout << "---------------------------------------------------------";
		cout << endl << endl << endl;
	//-------------------------------------------------------------------------------
	}
	
// Reset the queue
	cout << "The queue has been reset." << endl;
	q1.resetQueue();
	
// Reloading queue
	cout << "Reloading the queue..." << endl;
	qptr = &q1;
	for (int i = 0; i < MAX_QUEUE; ++i)
	{
		newItem = rand() % 101;
		qptr -> enqueue(newItem);
	}
	
// Creating a new Queue* to compare objects
	cout << "A new Queue is being created..." << endl << endl;
	Queue q2;
	Queue *qptr2 = &q2;
	for (int j = 0; j < 7; ++j)
	{
		newItem = rand() % 101;
		qptr2 -> enqueue(newItem);
	}
	
// Print the count of each queue
	cout << "Displaying the count of each queue:" << endl;
	cout << "Queue: q1" << "	";
	cout << "Count: " << q1.getCount() << endl;
	cout << "Queue: q2" << "	";
	cout << "Count: " << q2.getCount() << endl;
	
// Testing operator<
	cout << "Testing operator<..." << endl;
	bool isSmaller = qptr -> operator<(*qptr2);
	if (isSmaller)
		cout << "q1 < q2" << endl;
	else
		cout << "q1 ~< q2" << endl;
	
// Reset queues
	cout << endl;
	cout << "Both queues have been reset." << endl;
	q1.resetQueue();
	qptr = &q1;
	q2.resetQueue();
	qptr2 = &q2;
	
// Loading new values into the queues
	cout << "Reloading the queues..." << endl << endl;
	// q1 reset
	int randomSize = ((rand() % MAX_QUEUE) + 1);
	for (int k = 0; k < randomSize; ++k)
	{
		newItem = rand() % 101;
		qptr -> enqueue(newItem);
	}
	
	// q2 reset
	randomSize = ((rand() % MAX_QUEUE) + 1);
	for (int m = 0; m < randomSize; ++m)
	{
		newItem = rand() % 101;
		qptr2 -> enqueue(newItem);
	}
	
// Print the count of each queue
	cout << "Displaying the count of each queue:" << endl;
	cout << "Queue: q1" << "	";
	cout << "Count: " << q1.getCount() << endl;
	cout << "Queue: q2" << "	";
	cout << "Count: " << q2.getCount() << endl;
	
// Testing operator>
	cout << "Testing operator>..." << endl;
	bool isLarger = operator> (q1, q2);
	if (isLarger)
		cout << "q1 > q2" << endl;
	else
		cout << "q1 ~> q2" << endl;
	
// Using operator<< overloading to print the updated queues
	// q1
	cout << endl;
	cout << "Printing the queue:" << endl;
	cout << "v front" << endl;
	cout << *qptr;
	cout << "^ back" << endl;
	
	// q2
	cout << endl;
	cout << "Printing the queue:" << endl;
	cout << "v front" << endl;
	cout << *qptr2;
	cout << "^ back" << endl << endl;

	return 0;
}