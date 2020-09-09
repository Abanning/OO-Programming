// @filename: Test.cpp
// @author: Alex Banning (abanning)
// @assignment: Assignment 2 - Exceptions and Operator Overloading for Priority Queue
// @date: February 8th, 2019
// @description: QueueException header file.

#include <stdexcept>
#include <string>
using namespace std;

#ifndef QUEUEXCEPTION_H
#define QUEUEXCEPTION_H

class QueueException : public logic_error
{
public:
	QueueException(const string& message = "") : logic_error(message.c_str())
	{
	}  // end constructor
}; 
#endif// end QueueException
