// @author: Alex Banning
// @filename: Node.h
// @date: April 12th, 2019
// @assignment: Assignment 6 - Binary Search Tree
// @description: Node class header and implementation. Friend class of
//				 BinaryTree and BinarySearchTree classes.

// ADT Binary Tree Node:
// Spec and implementation file
//    data object: a node for a dynamic binary tree
//    operations: two constructors
// Friend classes: BinaryTree
// Contract: the items for the node are defined in class ItemType
//           and ItemType has a GOOD copy constructor

//#include "itemtype.h"

#ifndef NODE_H
#define NODE_H

#include <cstddef>

typedef int ItemType;
class Node
{
private:

	// creates a node
	// post: the item of the node is empty and the kids are NULL
	// usage: newptr = new cnode();
	Node() : mleftptr(NULL), mrightptr(NULL) {};

	// creates a node with a given item and kids
	// post: the item of the node is nodeItem, the kids are left and right
	// usage:aptr = new (nothrow) Node (thisone, NULL, NULL);
	// CAUTION: REQUIRES THAT COPY WORKS IN ItemType!!
	Node (const ItemType &nodeItem, Node* left, Node* right) : mitem (nodeItem), mleftptr (left), mrightptr (right) {};

	// implementation of data object
	//ItemType mitem;
	ItemType mitem;
	Node* mleftptr;
	Node* mrightptr;
	int mheight;

	friend class BinaryTree;
	friend class BinarySearchTree;
	friend class AVLBinSearchTree;
};
#endif