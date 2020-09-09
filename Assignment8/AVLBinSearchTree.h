// @author: Alex Banning
// @filename: AVLBinSearchTree.h
// @date: April 30th, 2019
// @assignment: Assignment 8 - AVL Binary Search Tree
// @description: AVL Binary Search Tree header file -- Paired with AVLBinSearchTree.cpp

#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "Node.h"
#include <iostream>
#include <cstddef>

const int MAXHEIGHT = 15;

// Search path struct
struct SearchPath
{
	Node* path[MAXHEIGHT];
	int size;
	int pivotIndex;
	SearchPath();
};

class AVLBinSearchTree : public BinarySearchTree
{
public:
	// Public methods

	// Default Constructor
	AVLBinSearchTree();
	
	// Copy Constructor
	AVLBinSearchTree(const AVLBinSearchTree &rhsTree);

	// Desctrutor
	~AVLBinSearchTree();
	
	// @description: Assignment operator overload. Copies the tree on the rhs of '='
	// @pre: rhsTree exists
	// @post: *this = rhsTree
	// @usage: AVLBinSearchTree copyTree = myAVLTree;
	AVLBinSearchTree& operator=(const AVLBinSearchTree& rhsTree);

	// @description: Inserts a new item into the AVL and rebalances
	// @pre: newItem is the new item, and the tree exists
	// @post: the item has been added to the tree if it does not already exist.
	//		  tree has been rotated if necessary
	//@ usage: myAVLTree.Insert(6);
	void Insert(const ItemType &newItem);

private:
	// Private helpers and data members
	
	// @description: Insert helper and creates a search path for the new item added
	// @pre: the tree exists, newItem is the new item, treeptr is the root of a subtree
	// @post: search contains the search path, the item has been added
	//@ usage: addNewEntryAndMakeSearchPath(newItem, mroot, search);
	void addNewEntryAndMakeSearchPath(const ItemType &newItem, Node* &treeptr, SearchPath &search);
	
	// @description: checks to see if a new node has no pivot
	// @pre: none
	// @post: search contains the search path, returns true if there is no pivot, false otherwise
	//@ usage: if(hasNoPivot(search)
	bool hasNoPivot(SearchPath &search);
	
	// @description: fixes the balance of all nodes
	// @pre: search contains the search path of the node
	// @post: fixes the mheight values on the nodes in a search path
	//@ usage: fixBalances(search, 0);
	void fixBalances(const SearchPath &search, int start);
	
	// @description: checks to see if a node was added to short side
	// @pre: search contains the search path
	// @post: returns true if it was added to short path, false otherwise
	//@ usage: if(isAddedToShortSide(search))
	bool isAddedToShortSide(const SearchPath &search);
	
	// @description: checks to see if a single right rotation is necessary
	// @pre: search contains the search path of the node
	// @post: returns true if needs to rotate right, false otherwise
	//@ usage: if(isSingleRotateRight(search))
	bool isSingleRotateRight(const SearchPath &search);
	
	// @description: checks to see if a single left rotation is necessary
	// @pre: search contains the search path of the node
	// @post: returns true if needs to rotate left, false otherwise
	//@ usage: if(isSingleRotateLeft(search))
	bool isSingleRotateLeft(const SearchPath &search);
	
	// @description: checks to see if a double rotation is necessary
	// @pre: search contains the search path of the node
	// @post: returns true if needs to rotate twice, false otherwise
	//@ usage: if(isDoubleRotateLeftRight(search))
	bool isDoubleRotateLeftRight(const SearchPath &search);
	
	// @description: rotates once to the left
	// @pre: search contains the search path of a node
	// @post: rotates the nodes left
	//@ usage: mroot = doSingleRotateLeft(search);
	Node* doSingleRotateLeft(SearchPath &search);
	
	// @description: rotates once to the right
	// @pre: search contains the search path of a node
	// @post: rotates the nodes right
	//@ usage: mroot = doSingleRotateRight(search);
	Node* doSingleRotateRight(SearchPath &search);
	
	// @description: does a double rotation, first left then right
	// @pre: search contains the search path of a node
	// @post: does the double rotation
	//@ usage: mroot = doDoubleRotateLeftRight(search);
	Node* doDoubleRotateLeftRight(SearchPath &search);
	
	// @description: does a double rotation, first right then left
	// @pre: search contains the search path of a node
	// @post: does the double rotation
	//@ usage: mroot = doDoubleRotateRightLeft(search);
	Node* doDoubleRotateRightLeft(SearchPath &search);
};