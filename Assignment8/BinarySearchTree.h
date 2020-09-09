// @author: Alex Banning
// @filename: BinarySearchTree.h
// @date: April 12th, 2019
// @assignment: Assignment 6 - Binary Search Tree
// @description: BinarySearchTree header file. To be paired with BinarySearchTree.cpp

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTree.h"
#include "Node.h"

class BinarySearchTree: public BinaryTree
{
public:
	//@creates a new binary search tree
	//@post: an empty binary search tree object exists
	//@usage: BinarySearchTree bst;
	BinarySearchTree();

	//@releases memory for a binary search tree
	//@pre: binary search tree object exists
	//@post: binary search tree object does not exist
	//@usage: automatically done at end of scope
	~BinarySearchTree();

	// *****************************************************************
	// *  pre for all member functions: binary search tree object exists
	// *****************************************************************

	//@searches for a key in a binary search tree object and
	//    retrieves the corresponding item
	//@pre: key has been assigned.
	//@post: theItem contains tkey with rest of the item if
	//    tkey is found in the binary search tree object
	//    else an exception is thrown
	//@usage: bst.Retrieve (abbrev, meaning);
	bool Search(const ItemType &theItem) const;

	//@inserts a new item into the binary search tree
	//@pre: newItem has been assigned
	//@post: if the newItem's key is not already in the tree
	//       and there is memory available
	//         then the newItem is added to the tree
	//       else an exception is thrown
	//@usage: Insert(4);
	void Insert(const ItemType &newItem);
	
	//@removes an item from the binary search tree
	//@pre: theItem is the item for desired removal
	//@post: theItem has been removed from the BST if it exists,
	//		 nothing otherwise
	//@usage: myBST.remove(22);
	void remove(const ItemType& theItem);

protected:  
	// recursive helper functions
	//@recursively searches (modeling on binary search) for a key
	//@pre: treeptr is assigned. newItem is assigned.
	//@post: searches for tkey in the tree with treeptr's root.
	//    If tkey is found, theItem is the key together with the other
	//    parts of the item. Else an exception is thrown.
	//@usage: retrieveItem (mroot, key, rest);
	bool lookup(Node* treeptr, const ItemType &theItem) const;

	// Recursive helper function for Insert
	// pre: newItem is the new item to be placed in the tree, treeptr is pointing to a node in the tree
	// post: the item is added in the correct spot
	// usage: insertItem(mroot, 4);
	void insertItem(Node* &treeptr, const ItemType &newItem);
	
	// Recursive helper function for remove
	//@pre: theItem is the desired item for removal, treeptr is the root of a tree
	//@post: theItem has been removed from the tree with root treeptr and
	//		 reconstruction occurs on BST
	//@usage: removeItem(mroot, theItem);
	void removeItem(Node *& treeptr, const ItemType& theItem);
   
    // Recursive helper function to find the minimum item in a subtree
	//@pre: treeptr is the root of a subtree
	//@post: anItem contains the value of the smallest item in the subtree
	//		 returns false if it reaches a NULL point in the subtree, true otherwise
	//@usage: bool isNull = lookforMin(treeptr, theItem);
	bool lookforMin(Node* treeptr, ItemType &anItem) const;
	
	// Recursive helper function to find the maximum item in a subtree
	//@pre: treeptr is the root of a subtree
	//@post: anItem contains the value of the largest item in the subtree
	//		 returns false if it reaches a NULL point in the subtree, true otherwise
	//@usage: bool isNull = lookforMax(treeptr, theItem);
	// Unecessary for removal using inorder successor. Only needed for inorder predecessor
	//bool lookforMax(Node* treeptr, ItemType &anItem) const;  

};
#endif