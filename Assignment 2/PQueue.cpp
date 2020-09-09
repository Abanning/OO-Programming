// @filename: Test.cpp
// @author: Dr. Yanping Zhang edited by Alex Banning
// @assignment: Assignment 2 - Exceptions and Operator Overloading for Priority Queue
// @date: February 8th, 2019
// @description: Circular array-based implementation. The array has indeces to the front 
//				 and back of the queue. A counter tracks the number of items currently in the queue. 

#include "PQueue.h"  // header file
#include "QueueA.h"
#include<iostream>
using namespace std;

// @description: Default constructor
// @pre: none
// @post: PriorityQueue object has been created
// @usage: PriorityQueue p1;
PriorityQueue::PriorityQueue()
{
}  	// end default constructor

// @description: enqueues an item in the priority queue
// @pre: PriorityQueue object has been created, newItem contains the new item to be enqueued
// @post: newItem has been enqueued on the PriorityQueue. If Exception is thrown,
//		  a message is printed on the screen for the user about full queue.
// @usage: qptr -> enqueue(newItem);
void PriorityQueue::enqueue(const QueueItemType& newItem) throw (QueueException)
{
	if (count == MAX_QUEUE)
		throw QueueException ("enqueue(newItem) called on a full queue");
	else
	{  // queue is not full; insert item
		if(count==0)
		{
			back = (back+1) % MAX_QUEUE;
			items[back] = newItem;
		}
		else
		{
			if (newItem<=items[back])
			{
				back = (back+1) % MAX_QUEUE;
				items[back] = newItem;                   
			}
			else
			{ 
				int index=front;
				int index2=back;
				/*******************Find the right location for newItem**************************/
				while((index!=back)&&(newItem<=items[index]))
				{
					index=(index+1)%MAX_QUEUE;
				}
				/*******************Find the right location for newItem**************************/
             
				/*****Shift every item back 1 position from the end of the queue, in order to empty the location for newItem*******/
				while(index2!=index)
				{
					items[(index2+1)%MAX_QUEUE]=items[index2];
					index2=(index2+MAX_QUEUE-1)%MAX_QUEUE;
				}
				/****Shift every item back 1 position from the end of the queue, in order to empty the location for newItem******/
				items[(index+1)%MAX_QUEUE]=items[index];
				items[index]=newItem;
				back = (back+1) % MAX_QUEUE;
			}
		}
		++count;
	}  // end if
}  // end enqueue
// End of implementation file.
