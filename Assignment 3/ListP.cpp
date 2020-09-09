// @filename: ListP.cpp
// @author: Alex Banning
// @assignment: Assignment 3 - Quick Sort
// @date: March 1st, 2019
// @description: implementation file for class ListP

#include "ListP.h"
#include "ListNode.h"
#include <cstddef>
using namespace std;

ListP::ListP()
{
	size = 0;
	head = NULL;
}

ListP::ListP(const ListP &L1)
{
	int rhsize = L1.getSize(); // get size of list to copy
	ListNode* currentptr = L1.getHead(); // make currentptr tracker at head of L1
	head = new ListNode(); // make new head for L2 (the copier)
	ListNode* newptr = head; // make newptr tracker for L2 (the copier)
	
	// Begin copying
	for (int i = 1; i <= rhsize; ++i)
	{
		newptr -> setItem(currentptr -> getItem()); // copy item from L1 (copiee) -> L2 (copier)
		currentptr = currentptr -> getNext(); // increment currentptr tracker
		newptr -> setNext(new ListNode()); // creat new Node in copier List L2
		newptr = newptr -> getNext(); // increment newptr tracker
	}
	
	// Secure data
	currentptr = NULL;
	newptr = NULL;
}

ListP::~ListP()
{
	ListNode* delptr; // create deletion pointer for tracking
	
	for (int i = 1; i <= size; ++i)
	{
		delptr = head; // point at head first
		head = head -> getNext(); // move head
		delptr -> setNext(NULL); // remove connection
		delete delptr; // delete the node
		delptr = head; // move delptr to new head
	}
	
	// Secure data
	delptr = NULL;
	head = NULL;
	size = 0;
}

bool ListP::isEmpty() const
{
	return (size == 0);
}

int ListP::getSize() const
{
	return size;
}

ListNode* ListP::getHead() const
{
	return head;
}

void ListP::insert(int pos, const ItemType &x)
{
	ListNode* newptr = new ListNode(x); // create new node
	
	if (isEmpty()) // empty list case
	{
		head = newptr; // set front to new Node
	}
	else if (pos == 0) // at the front
	{
		newptr -> setNext(head);
		head = newptr;
		newptr = NULL;
	}
	else if (pos == size) // at tail
	{
		ListNode* backptr = getTail(head);
		
		backptr -> setNext(newptr);
		backptr = NULL;
	}
	else if (pos > size) // beyond the end
	{
		cout << "Position exceeds size of list. Item will be placed at the back of the list.";
		cout << endl;
		
		ListNode* back = getTail(head);
		back -> setNext(newptr);
		newptr -> setNext(NULL);
	}	
	else // somewhere in the middle
	{
		ListNode* currentptr = head; // start at head
		
		for (int i = 0; i < (pos - 1); ++i)
		{
			currentptr = currentptr -> getNext(); // find Node at 'pos' - 1
		}
	
		newptr -> setNext(currentptr -> getNext()); // reroute next item
		currentptr -> setNext(newptr); // reroute current item to point to next item
		
		// secure data
		currentptr = NULL;
		newptr = NULL;
	}

	size++;
	cout << "An item has been added to the list." << endl;
	cout << "Size: " << getSize() << endl;
}

void ListP::remove(int pos)
{
	bool hasBeenRemoved = false;
	
	if (isEmpty()) // empty list case
	{
		cout << "Cannot remove items from an empty list." << endl;
		cout << endl;
	}
	else if (pos == 0) // remove head
	{
		if (size == 1) // results in empty list
		{
			delete head;
			head = NULL;
			cout << "The list is now empty." << endl;
		}
		else // results in non-empty list
		{
			ListNode* delptr = head; // set delete ptr to head
			head = delptr -> getNext(); // move head to next item
			delete delptr; // delete node
			// Secure data
			delptr -> setNext(NULL);
			delptr = NULL;
		}
		hasBeenRemoved = true;
	}
	else if (pos == (size - 1)) // remove tail
	{
		ListNode* delptr = getTail(head); // get tail
		delete delptr; // delete Node
		// Secure data
		delptr -> setNext(NULL);
		delptr = NULL; // this will set previous node -> next to NULL
		hasBeenRemoved = true;
	}
	else if ((pos + 1) > size) // Outside bounds of list
	{
		cout << "Position exceeds the size of the list." << endl;
		cout << "No items will be removed from the list." << endl;
		cout << endl;
	}
	else // delete somewhere in the middle
	{
		ListNode* delptr = head; // start at head
		ListNode* tempptr1;
		ListNode* tempptr2;
	
		for (int i = 0; i < (pos - 1); ++i)
		{
			delptr = delptr -> getNext(); // increment delptr to node before desired removal
		}
	
		// Set temp to del
		tempptr1 = delptr;
		// Increment temp twice to get item after deletion point
		tempptr1 = tempptr1 -> getNext();
		tempptr2 = tempptr1; // Deletion point
		tempptr1 = tempptr1 -> getNext();
		
		// Link items
		delptr -> setNext(tempptr1); // set next to item after
		tempptr2 -> setNext(NULL); // break connection
		delptr = tempptr2;
		delete delptr; // delete Node
		// Secure Data
		delptr = NULL;
		tempptr1 = NULL;
		tempptr2 = NULL;
		
		hasBeenRemoved = true;
	}
	
	if (hasBeenRemoved)
	{
		size--;
		cout << "An item has been removed from the list." << endl;
		cout << "Size: " << size << endl;
	}
}

void ListP::display() const
{
	ListNode* currentptr = head; // start at head
	
	cout << "Size: " << size << endl;
	cout << "front ----> ";
	for (int i = 0; i < size; ++i)
	{
		cout << currentptr -> getItem() << " "; // display item
		currentptr = currentptr -> getNext(); // increment currenptr
	}
	cout << "<---- back";
	cout << endl << endl;
}

void ListP::sort_quicksort()
{
	cout << "Sorting....." << endl;
	cout << "----------------------------------------" << endl;
	head = quicksort(head);
	cout << "----------------------------------------" << endl;
	cout << "Sorting complete." << endl;
	cout << endl;
}

ListNode* ListP::merge(ListNode* head1, ListNode* head2)
		{
			if (head2 == NULL)
			{
				return head1;
			}
			else if (head1 == NULL)
			{
				return head2;
			}
			else if (head1 > head2)
			{
				head1 -> setNext(merge(head1 -> getNext(), head2));
				return head1;
			}
			else
			{
				head2 -> setNext(merge(head1, head2 -> getNext()));
				return head2;
			}
		}

// Private methods---------------------------------------------------------------------------------
void ListP::partition(ListNode* &Larger, ListNode* &Smaller, ListNode* &pivot)
{
	ListNode* currentptr = pivot -> getNext(); // start tracker at point after pivot
	ListNode* largerptr = NULL;
	ListNode* smallerptr = NULL;
	pivot -> setNext(NULL); // cut the pivot point
	cout << "Pivot: " << pivot -> getItem() << endl;
	int sizeL = 0;
	int sizeS = 0;
	
	cout << "In Partition..." << endl;
	
	while (currentptr != NULL)
	{
		if (currentptr -> getItem() > pivot -> getItem()) // item is larger than pivot
		{
			if (Larger == NULL)
			{
				Larger = currentptr; // set the head of larger
				currentptr = currentptr -> getNext(); // increment tracker
				Larger -> setNext(NULL); // make cut
				sizeL++; // increment size
			}
			else
			{
				largerptr = Larger; // start larger tracker at head
				while (largerptr -> getNext() != NULL)
				{
					largerptr = largerptr -> getNext(); // stop one item before NULL
				}
				largerptr -> setNext(currentptr); // set next item to larger item
				currentptr = currentptr -> getNext(); // increment tracker
				largerptr = largerptr -> getNext(); // increment larger tracker
				largerptr -> setNext(NULL); // make cut
				sizeL++; // increment size
			}
		}
		else
		{
			if (Smaller == NULL)
			{
				Smaller = currentptr; // set the head of Smaller
				currentptr = currentptr -> getNext(); // increment tracker
				Smaller -> setNext(NULL); // make cut
				sizeS++; // increment size
			}
			else
			{
				smallerptr = Smaller; // start smaller tracker at head
				while (smallerptr -> getNext() != NULL)
				{
					smallerptr = smallerptr -> getNext(); // increment smaller tracker
				}
				smallerptr -> setNext(currentptr); // set next item to smaller item
				currentptr = currentptr -> getNext(); // increment tracker
				smallerptr = smallerptr -> getNext(); // increment smaller tracker
				smallerptr -> setNext(NULL); // make cut
				sizeS++; // increment size
			}
		}
	}
	
	cout << "Size of Larger: " << sizeL << endl;
	cout << "Size of Smaller: " << sizeS << endl;
	cout << endl;
}

ListNode* ListP::quicksort(ListNode* begin)
{
	cout << "In quicksort..." << endl;
	if (begin == NULL || begin -> getNext() == NULL) // empty or 1-item list return just the head or NULL
	{
		return begin;
	}
	else // larger than 1 item needs to be sorted
	{
		ListNode* Larger = NULL;
		ListNode* Smaller = NULL;
		
		partition(Larger, Smaller, begin); // Larger and Smaller NULL, pivot is first element
		ListNode* largerHead = quicksort(Larger); // sort larger
		ListNode* smallerHead = quicksort(Smaller); // then sort smaller
		if (largerHead == NULL && smallerHead != NULL) // no items larger
		{
			if (begin == NULL)
			{
				getTail(smallerHead) -> setNext(largerHead);
			}
			else
			{
				getTail(smallerHead) -> setNext(begin); // glue smaller and pivot
			}
			cout << "Leaving quicksort..." << endl;
			return smallerHead; // return smaller
		}
		else if (largerHead -> getNext() == NULL && smallerHead != NULL) // one item larger
		{
			if (begin == NULL)
			{
				getTail(smallerHead) -> setNext(largerHead);
			}
			else
			{
				getTail(smallerHead) -> setNext(begin); // glue smaller and pivot
				begin -> setNext(largerHead); // glue smaller/pivot and larger
			}
			cout << "Leaving quicksort..." << endl;
			return smallerHead; // return smaller
		}
		if (smallerHead == NULL) // no items smaller
		{
			begin -> setNext(largerHead); // glue pivot and larger
			cout << "Leaving quicksort..." << endl;
			return begin; // return pivot
		}
		else if (smallerHead -> getNext() == NULL) // one item smaller
		{
			smallerHead -> setNext(begin); // glue smaller and pivot
			begin -> setNext(largerHead); // glue smaller/pivot and larger
			cout << "Leaving quicksort..." << endl;
			return smallerHead;
		}
	}
}

ListNode* ListP::getTail(ListNode* begin)
{
	ListNode* currentptr = begin; // start at front
	
	while ((currentptr != NULL) && (currentptr -> getNext() != NULL))
	{
		currentptr = currentptr -> getNext();
	}
	
	return currentptr;
}