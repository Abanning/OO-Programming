// @author: Alex Banning
// @filename: main.cpp
// @date: April 12th, 2019
// @assignment: Assignment 6 - Binary Search Tree
// @description: This is the main client program for the implementation of a binary search tree
//				 This program creates a search tree and tests its member functions like Search
//				 and 3 different traversals (preorder, inorder, and postorder).

#include "AVLBinSearchTree.h"
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "Node.h"
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	AVLBinSearchTree myAVLTree;
	int seed = time(0);
	srand(seed);
	ItemType x;
	
	for (int i = 0; i < 10; ++i)
	{
		x = rand() % 101;
		myAVLTree.Insert(x);
	}
	
	// Display original tree
	cout << endl;
	cout << "Displaying Tree:" << endl;
	cout << endl;
	myAVLTree.inorderTraverse();
	cout << endl;
	
	// Make a copy using assignment
	AVLBinSearchTree copyAVLTree = myAVLTree;
	// Print Copy
	cout << "Displaying the copy:" << endl;
	cout << endl;
	copyAVLTree.inorderTraverse();
	cout << endl;
	
	// Copy using copy constructor
	AVLBinSearchTree copyAVLTree2(myAVLTree);
	cout << "Displaying the second copy:" << endl;
	cout << endl;
	copyAVLTree2.inorderTraverse();
	cout << endl;
	
	return 0;
}