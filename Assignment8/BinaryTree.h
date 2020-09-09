// @author: Alex Banning
// @filename: BinaryTree.h
// @date: April 12th, 2019
// @assignment: Assignment 6 - Binary Search Tree
// @description: BinaryTree header file. To be paired with BinaryTree.cpp.

// Specification of ADT Binary Tree
//    Data object: A binary tree T that is either empty or in the form
// you finish




// Operations: (a scaled-down version)
//			    create, destroy, copy, operator=,
//              traversals (preorder, inorder, postorder)
// Contract: Assumes the this class can access private data members of class cnode.
//    		 Those data members are: citem mitem, cnode* mleftptr, cnode* mrightptr.
//    		 There is a constructor that allows caller to give item, left and right ptrs.

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"
#include <iostream>
using namespace std;


class BinaryTree
{
public:
	// creates an empty binary tree
	// post: object is an empty binary tree
	// usage: BinaryTree zags;
	BinaryTree();
	
	BinaryTree(const ItemType &rootItem);
	
	BinaryTree(const ItemType &rootItem, BinaryTree &leftTree, BinaryTree &rightTree);  

	// creates a new binary tree that is a copy of an existing tree
	// post: object is a copy of rhstree
	// usage: BinaryTree zags (bulldog);
	BinaryTree(const BinaryTree &rhstree);
   
  

	// releases the memory of a binary tree
	// pre: object exists
	// post: memory for the object has been released. object theoretically does not exist
	//       but in practice, it is empty.
	~BinaryTree();

	// ******************** member functions ********************************************
	// pre: binary tree object exists
	// **********************************************************************************
	// post: returns true if the object is empty; else returns false
	// usage: if (tree.isEmpty())
	bool isEmpty() const;

	// pre: rhstree is an assigned tree.
	// post: object is a copy of rhstree
	// usage: atree = btree = ctree;
	// BinaryTree& operator=(const BinaryTree& rhstree);

	// prints the tree to look like a computer science tree
	// post: outputs the tree as in the example below
	//
	//                        bar
	//                  foo
	//                        geeU
	//  root ->  queue
	//                        stack
	//                  list
	//                        array
	// nodes at the same level are indented the same.
	// Viewer must rotate head 90 degrees in order to look like a cs tree
	// usage: tree.PrettyDisplay();
	//   void PrettyDisplay() const;

	// *************** on the following traversals
	// uses: operator<< from citem
	// post: prints the objects in the tree in order specified
	// usage: tree.PreorderTraverse();  
	// similarly for the other traversals
	// *****************************************************

	void preorderTraverse() const;
	void inorderTraverse() const;
	void postorderTraverse() const;

	// temporary function to be removed when BinaryTree has children
	// post: makes a complete binary tree of height 3 for testing purposes
	// usage: tree.MakeTree();
	// void MakeTree() throw (cexception);

protected:   
	// recursive helper functions for coding member functions



	// Copies one binary tree to another
	// pre: oldtreep points to the root of a binary tree
	// post: newtreep points to the root of a binary tree
	//  that has copies of the nodes of oldtreep's tree
	// usage: copyTree (newptr, oldptr);
	void copyTree(Node* &newtreep, Node* oldtreep); 

	// Releases memory for a binary tree
	// pre: treep points to the root of a binary tree
	// post: releases all of the nodes in the tree pointed to by treep
	//    and leaves treep empty.
	// usage: destroyTree (mroot);
	void destroyTree(Node* &treep);
/*
	// recursive helper for prettyDisplay. You do the doc
	// void writePretty (Node* treep, int level);

	// ********** recursive helpers for the traversals ****************
	// pre: treep points to the root of a binary tree to be traversed
	// post: prints the objects of the nodes on the screen in the 
	//     specified order
	// usage: preorder (mroot);   
	//    similarly for the others


*/
	void preorder(Node* treep) const;
	void inorder(Node* treep) const;
	void postorder(Node* treep) const;

	// data member
 
	Node* mroot;
};
#define BINARYTREE_H
#endif