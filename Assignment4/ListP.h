// @filename: ListP.h
// @author: Alex Banning
// @assignment: Assignment 4 - Merge Sort
// @date: March 27th, 2019
// @description: header file for class ListP. Paired with ListP.cpp

#include <iostream> 
#include "ListNode.h"


#ifndef _LISTP
#define _LISTP
using namespace std;

class ListP
{
	public:
		// @description: default constructor
		// @pre: none
		// @post: List object is created
		// @usage: ListP myList;
		ListP();
		
		// @description: Copy constructor
		// @pre: L1 is created and is a list
		// @post: *this is a copy of L1
		// @usage: ListP myList2(myList);
		ListP(const ListP &L1);
		
		// @description: Desctructor
		// @pre: a list exists
		// @post: a list does not exist
		// @usage: automatically called at end of scope
		~ListP();

		// @description: tests to see if a list is empty
		// @pre: a list exists
		// @post: returns true if the list is empty, false otherwise
		// @usage: if (L1.isEmpty())
		bool isEmpty() const;
	
		// @description: returns the size of a list
		// @pre: list exists
		// @post: returns the number of items in the list
		// @usage: int listSize = L1.getSize();
		int getSize() const;  
		
		// @description: returns a pointer to the head of a list
		// @pre: list exists
		// @post: returns the address of the head of the list as a pointer
		// @usage: ListNode* headOfList = L1.getHead();
		ListNode* getHead() const;

		// @description: inserts an item into the list
		// @pre: the list object has been created, pos is the desired index, x is the value to be stored
		// @post: x has been inserted into the list at position 'pos'
		// @usage: myList.insert(pos, x);
		void insert(int pos, const ItemType &x);
		
		// @description: removes an item from the list as long as 'pos' is smaller than the size
		// @pre: the list object has been created, 
		// @post: the item in position 'pos' has been removed
		// @usage: myList.remove(0);
		void remove(int pos);
		
		// @description: displays the contents of a list
		// @pre: the list exists and is not empty
		// @post: displays the list on the screen
		// @usage: myList.display();
		void display() const;
		
		// @description: sorts the list using quicksort algorithm
		// @pre: the list exists
		// @post: the list is sorted and head is updated
		// @usage: myList.sort_quicksort();
		void sort_quicksort();
		
		// @description: sorts the list using mergesort algorithm
		// @pre: the list exists
		// @post: the list is sorted and head is updated
		// @usage: myList.sort_mergesort();
		void sort_mergesort();
     
     
	private:
		// Data members
		int size; // how many items in the list
		ListNode* head; // the head of the list
		
		// @description: cuts the list into 3 separate lists: a pivot, Smaller than the pivot,
		// 				 and Larger than the pivot.
		// @pre: pivot is contains the address of the head of the original list, Smaller = Larger = NULL
		// @post: the list has been cut into 3 pieces
		// @usage: partition(Larger, Smaller, begin);
		void partition(ListNode* &Larger, ListNode* &Smaller, ListNode* &pivot );
		
		// @description: merges two lists together in descending order
		// @pre: head1 is the head node of list 1, head2 is the head node of list 2
		// @post: returns the new head of a sorted list
		// @usage: ListNode* newptr = merge(lhead1, lhead2);
		ListNode* merge(ListNode* head1, ListNode* head2);
		
		// @description: sorts a list given its size and head -- 
		//				 returns the head of a sorted list
		// @pre: lhead is the head of the list, lsize is the size of the list.
		// @post: returns the new head of a sorted list.
		// @usage: head = mergesort(head, size);
		ListNode* mergesort(ListNode* lhead, int lsize);
		
		// @description: quicksort helper function. Recursively calls itself to sort a list
		// @pre: begin contains the head of the list to be sorted
		// @post: returns the address of the new head of the sorted list
		// @usage: quicksort(begin); or quicksort(Larger); or ListNode* smallerHead = quicksort(Smaller);
		ListNode* quicksort(ListNode* begin);
		
		// @description: gets the tail of a linked list
		// @pre: begin is the head node of the linked list
		// @post: returns the address of the last node before -> NULL
		// @usage: ListNode* tail = getTail(head);
		ListNode* getTail(ListNode* begin);
};

#endif