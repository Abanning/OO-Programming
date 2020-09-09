// @filename: Test.cpp
// @author: Alex Banning (abanning)
// @assignment: Assignment 2 - Exceptions and Operator Overloading for Priority Queue
// @date: February 8th, 2019
// @description: Circular array-based implementation. The array has indexes to the front 
//				 and back of the queue. A counter tracks the number of items currently in the queue.

#include "QueueA.h"  // header file
#include <iostream>
using namespace std;

// Friend and non-member function implementation----------------------------------------

// @description: operator<< overload for printing queue by returning output
// @pre: Queue object exists
// @post: returns the contents of the queue
// @usage: cout << q1 << endl;
ostream& operator<<(ostream& output, const Queue& q)
{
	int currentIndex;
	if (!q.isEmpty())
	{
		currentIndex = q.front; // start at front of queue
		for (int currentIndex = q.front; (currentIndex != (q.back + 1)) && 
											(currentIndex < (q.count + MAX_QUEUE)); ++currentIndex)
		{
			output << q.items[currentIndex] << endl;
			currentIndex = (currentIndex + 1) % MAX_QUEUE;
		}
		output << q.items[q.back] << endl;
	}
	
	return output;
}

// @description: Displays the queue on the screen
// @pre: Queue object has been created
// @post: displays the queue on the screen. If Exception is thrown,
//		  will print a message to the user
// @usage: qptr -> display();
void display(const Queue& q1)
{
	int index = 1;
    int item_in = q1.front;
	if (q1.isEmpty())
	{
		cout << "The queue is empty." << endl;
	}
	else
	{
		cout << "Printing the queue: " << endl << endl;
		cout << "v front " << endl;
		while(index <= q1.count)
		{
			cout << q1.items[item_in] << endl;
			item_in = (item_in + 1) % MAX_QUEUE;
			index++;
		}
		cout << "^ back" << endl << endl;
	}
}

// @description: checks to see if one queue has more items than another
// @pre: both queue objects have been created and are not empty
// @post: returns true if q1 > q2, false otherwise
// @usage: isLarger = operator> (q1, q2)
bool operator> (const Queue& q1, const Queue& q2)
{
	if (q1.getCount() > q2.getCount())
		return true;
	return false;
}

//Member function implementation-------------------------------------------------------

// @description: default constructur
// @pre: none
// @post: Queue object is created
// @usage: Queue q1;
Queue::Queue() : front(0), back(MAX_QUEUE-1), count(0)
{
}  // end default constructor

// @description: checks to see if the queue is empty
// @pre: Queue object exists
// @post: returns true if queue is empty, false otherwise
// @usage: if(isEmpty())...
bool Queue::isEmpty() const
{
	return count == 0;
}  	// end isEmpty


// @description: enqueues an item in the queue
//				 may throw Exception: QueueException 
// @pre: Queue object has been created, newItem contains a value
// @post: enqueues the newItem in the queue if the queue is not full,
//		  prints a message if the Exception is thrown for a full queue
// @usage: qptr -> enqueue(4);
void Queue::enqueue(const QueueItemType& newItem) throw (QueueException)
{
	if (count == MAX_QUEUE)
		throw QueueException ("enqueue(&newItem) called on a full queue");
	else
	{  // queue is not full; insert item
		back = (back+1) % MAX_QUEUE;
		items[back] = newItem;
		++count;
	}  // end if
}  	// end enqueue

// @description: dequeues the front item of the queue
//				 may throw Exception: QueueException
// @pre: Queue object has been created
// @post: dequeues the front item in the queue if the queue is not empty,
//		  and queueFront contains the item that was juat removed. If
//		  Exception is thrown, will print a message to the user
// @usage: qptr -> dequeue(frontItem);
void Queue::dequeue(QueueItemType& queueFront) throw (QueueException)
{
	if (isEmpty())
		throw QueueException ("dequeue(&queueFront) called on an empty queue");
	else
	{  // queue is not empty; remove front
		queueFront = items[front];
		front = (front+1) % MAX_QUEUE;
		--count;
	}  // end if
}  	// end dequeue

// @ description: gets the front item from the queue (without removing it)
//				  May throw Exception: QueueException
// @pre: Queue object has been created
// @post: queueFront contains the front item of the queue. If Exception is thrown
//		  will print a message to the user
// @usage: qptr -> getFront(frontItem);
void Queue::getFront(QueueItemType& queueFront) const throw (QueueException)
{
	if (isEmpty())
		throw QueueException ("getFront() called on an empty queue");
	else
		// queue is not empty; retrieve front
		queueFront = items[front];
}  	// end getFront
// End of implementation file.

// @description: gets the count of items from the queue
// @pre: Queue object has been created
// @post: returns the number of items in the queue
// @usage: count = qptr -> getCount;
int Queue::getCount() const
{
	return count;
}

// @description: checks to see if one queue has fewer items than another
// @pre: both queue objects have been created and are not empty
// @post: returns true if q1 < q2, false otherwise
// @usage: isSmaller = qptr -> operator< (q2)
bool Queue::operator< (const Queue& q2)
{
	if (this -> count < q2.count)
		return true;
	return false;
}

// @description: Resets all of the queue data members
// @pre: Queue has data in it
// @post: front = 0; back = MAX_QUEUE - 1; count = 0;
// @usage: qptr -> resetQueue();
void Queue::resetQueue()
{
	front = 0;
	back = MAX_QUEUE - 1;
	count = 0;
}
