// @filename: ListNode.h
// @author: Alex Banning
// @assignment: Assignment 3 - Quick Sort
// @date: March 1st, 2019
// @description: header file for class ListNode. Paired with ListNode.cpp

#ifndef _LISTNODE
#define _LISTNODE

typedef int ItemType;

class ListNode
{
	public:
		// @description: default constructor
		// @pre: none
		// @post: a ListNode has been created
		// @usage: ListNode* currentptr;
		ListNode();
		
		// @description: sceondary constructor
		// @pre: x is the item to be stored in the node
		// @post: The ListNode has been created with item = x;
		// @usage: ListNode firstNode(23);
		ListNode(const ItemType &x);
		
		// @description: secondary constructor
		// @pre: x is the item to be stored and nNode is the next pointer
		// @post: the ListNode has been created with item = x and next = nNode
		// @usage: n/a
		ListNode(const ItemType &x, ListNode* nNode);
		
		// @description: returns the item in a node
		// @pre: the node exists
		// @post: returns the item in the node
		// @usage: ItemType Item = currentptr -> getItem();
		ItemType getItem();
		
		// @description: returns the next pointer from a node
		// @pre: the node exists
		// @post: returns the address of the next linked node
		// @usage: currentptr = currentptr -> getNext();
		ListNode* getNext();
		
		// @description: sets the item in a node
		// @pre: the node exists, x is the item to be stored
		// @post: the item is stored in the node
		// @usage: currentptr -> setItem(x);
		void setItem(const ItemType &x);
		
		// @description: sets the next pointer of a node
		// @pre: the node exists, nNode contains the address of the next node
		// @post: the node is linked to the next node i.e. next = nNode
		// @usage: currentptr -> setNext(begin);
		void setNext(ListNode* nNode);
		
		// @description: destructor
		// @pre: the ListNode object exists
		// @post: the ListNode object does not exist
		// @usage: automatically called at the end of scope
		~ListNode();

	private :
		// Data Members
		ItemType item; // A data item
		ListNode* next; // Pointer to next node
		
	friend class List;
}; // end Node

#endif