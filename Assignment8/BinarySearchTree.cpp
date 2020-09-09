// @author: Alex Banning
// @filename: BinarySearchTree.cpp
// @date: April 12th, 2019
// @assignment: Assignment 6 - Binary Search Tree
// @description: Implementation file for BinarySearchTree. Utilizes Insert and Search methods
//				 for binary search

#include "BinarySearchTree.h"
#include <iostream>
#include <cstddef>
using namespace std;

// Constructors and Destructors
BinarySearchTree::BinarySearchTree()
{
	mroot = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
	destroyTree(mroot);
	mroot = NULL;
}

// Public Methods------------------------------------------------------------------------------------

bool BinarySearchTree::Search(const ItemType &theItem) const
{
	return lookup(mroot, theItem);
}

void BinarySearchTree::Insert(const ItemType &newItem)
{
	insertItem(mroot, newItem);
}

bool BinarySearchTree::lookup(Node* treeptr, const ItemType &theItem) const
{
	if (treeptr -> mitem == theItem)
	{
		return true;
	}
	else if (theItem < treeptr -> mitem)
	{
		if (treeptr -> mleftptr == NULL)
			return false;
		else
			lookup(treeptr -> mleftptr, theItem);
	}
	else
	{
		if (treeptr -> mrightptr == NULL)
			return false;
		else
			lookup(treeptr -> mrightptr, theItem);
	}
}

void BinarySearchTree::insertItem(Node* &treeptr, const ItemType &newItem)
{
	if (treeptr == NULL) // empty tree
	{
		treeptr = new Node(newItem, NULL, NULL); // Create new node
	}
	else
	{
		if (newItem <= treeptr -> mitem) // if newItem is smaller than or equal to root, move to left subtree
		{
			insertItem(treeptr -> mleftptr, newItem);
		}
		else // Move to right subtree if larger
		{
			insertItem(treeptr -> mrightptr, newItem);
		}
	}
}

void BinarySearchTree::remove(const ItemType& theItem)
{
	removeItem(mroot, theItem);
}

// Private Methods-------------------------------------------------------------------------------------

void BinarySearchTree::removeItem(Node* &treeptr, const ItemType &theItem)
{
	if (treeptr != NULL) // Not a null node
	{
		if (theItem == treeptr -> mitem) // The node contains the item
		{
			if (treeptr -> mrightptr == NULL && treeptr -> mleftptr == NULL) // No children
			{
				delete treeptr; // delete node
				treeptr = NULL; // secure data
			}
			else if (treeptr -> mrightptr != NULL && treeptr -> mleftptr == NULL) // One right child
			{
				Node* delptr = treeptr; // assign delete pointer
				treeptr = treeptr -> mrightptr; // assign new node
				
				delptr -> mrightptr = NULL; // 
				delete delptr;
				delptr = NULL;
			}
			else if (treeptr -> mrightptr == NULL && treeptr -> mleftptr != NULL) // One left child
			{
				Node* delptr = treeptr;
				treeptr = treeptr -> mleftptr;
				
				delptr -> mleftptr = NULL;
				delete delptr;
				delptr = NULL;
			}
			else // Two children
			{
				ItemType minimumItem;
				
				lookforMin(treeptr -> mrightptr, minimumItem); // Search for smallest and store it in minimumItem
				treeptr -> mitem = minimumItem; // Make new assignment with inorder successor
				removeItem(treeptr -> mrightptr, minimumItem); // Delete node that replaced original
			}
			
			cout << "Item: " << theItem << " has been removed from the BST." << endl;
			cout << endl;
		}
		else if (theItem <= treeptr -> mitem)
		{
			removeItem(treeptr -> mleftptr, theItem);
		}
		else
		{	
			removeItem(treeptr -> mrightptr, theItem);
		}
	}
	else
	{
		cout << "The item was not found in the BST." << endl;
	}
}

bool BinarySearchTree::lookforMin(Node* treeptr, ItemType &anItem) const
{
	if (treeptr != NULL)
	{
		bool isNull = lookforMin(treeptr -> mleftptr, anItem);
		
		if (isNull)
			anItem = treeptr -> mitem;
		
		return false;
	}
	else
		return true;
}

// Unnecessary for removal implementation. Only used if inorder predecessor is
// desired instead of inorder successor.
/*
bool BinarySearchTree::lookforMax(Node* treeptr, ItemType &anItem) const
{
	if (treeptr != NULL)
	{
		bool isNull = lookforMax(treeptr -> mrightptr, anItem);
		
		if (isNull)
			anItem = treeptr -> mitem;
		
		return false;
	}
	else
		return true;
}*/
