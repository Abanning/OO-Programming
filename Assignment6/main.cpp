// @author: Alex Banning
// @filename: main.cpp
// @date: April 12th, 2019
// @assignment: Assignment 6 - Binary Search Tree
// @description: This is the main client program for the implementation of a binary search tree
//				 This program creates a search tree and tests its member functions like Search
//				 and 3 different traversals (preorder, inorder, and postorder).

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
	// Declarations
	BinarySearchTree myTree;
	int seed = time(0);
	srand(seed);
	ItemType newItem;
	ItemType testRemoval[20];
	cout << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << endl;
	
	// Build tree
	for (int i = 0; i < 20; ++i)
	{
		newItem = rand() % 101; // make a random number from 0-100
		
		testRemoval[i] = newItem; // store the items in array for later testing
		
		myTree.Insert(newItem);
	}
	
	// Test inorder traversal
	cout << "Displaying the BST..." << endl;
	cout << endl;
	myTree.inorderTraverse();
	cout << endl;
	
	// Test removal
	cout << "Testing removal..." << endl;
	int index = 0;
	for (int j = 0; j < 5; ++j)
	{
		index = rand() % 20; // pick a random index
		
		myTree.remove(testRemoval[index]); // Remove items
	}
	
	// Show new tree
	cout << "Displaying the BST..." << endl;
	cout << endl;
	myTree.inorderTraverse();
	cout << endl;
	
	cout << "-------------------------------------------------------------------------" << endl;
	cout << endl;
	
	
	return 0;
}