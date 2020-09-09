// @filename: main.cpp
// @author: Alex Banning
// @assignment: Assignment 3 - Quick Sort
// @date: March 1st, 2019
// @description: Main client program for quicksort of a Linked List

#include <iostream>
#include <cstddef>
#include <ctime>
#include <cstdlib>
#include "ListNode.h"
#include "ListP.h"
using namespace std;

int main()
{
	/*// Notice
	cout << endl << endl;
	cout << "**Warning: This program has an error in the display function that leads**" << endl;
	cout << "**to a segmentation fault on occassion. I could not solve the probelm;**" << endl;
	cout << "**however, the sorting algorithm works correctly. Please run the program until**" << endl;
	cout << "**the desired output is achieved -- 1 unsorted list displayed and 1 sorted**" << endl;
	cout << "**list displayed. Thank you for your understanding.**" << endl;
	cout << endl << endl;*/
	
	// Variable declarations
	ListP myList;
	int x;
	int pos = 0;
	
	// Random num seeding
	int seed = time(0);
	srand(seed);
	
	cout << endl;
	
	// Filling list
	for (int i = 0; i < 6; ++i)
	{
		x = rand() % 51;
		myList.insert(pos, x);
		pos++;
	}	
	
	// Displaying list (unsorted)
	cout << endl;
	cout << "Unsorted list" << endl;
	myList.display();
	cout << endl << endl;
	
	// Sorting and display
	myList.sort_quicksort();
	cout << endl;
	cout << "Sorted list" << endl;
	myList.display();
	cout << endl << endl;
	
	return 0;
}