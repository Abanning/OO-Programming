// @filename: main.cpp
// @author: Alex Banning
// @assignment: Assignment 4 - Merge Sort
// @date: March 27th, 2019
// @description: Main client program for merge sort of a Linked List

#include <iostream>
#include <cstddef>
#include <ctime>
#include <cstdlib>
#include "ListNode.h"
#include "ListP.h"
using namespace std;

int main()
{
	// Variable declarations
	ListP myList;
	int x;
	int pos = 0;
	
	// Random num seeding
	int seed = time(0);
	srand(seed);
	
	// For spacing
	cout << endl;
	
	// Filling list
	for (int i = 0; i < 20; ++i)
	{
		x = rand() % 1001;
		myList.insert(pos, x);
		pos++;
	}	
	
	// Displaying list (unsorted)
	cout << endl << endl;
	cout << "Unsorted list" << endl;
	myList.display();
	cout << endl << endl;
	
	// Sorting and displaying
	cout << "Size: " << myList.getSize() << endl;
	cout << endl;
	myList.sort_mergesort();
	cout << endl;
	cout << "Sorted list:" << endl;
	myList.display();
	cout << endl << endl;
	
	return 0;
}