// @author: Alex Banning
// @filename: BinaryTree.cpp
// @date: April 12th, 2019
// @assignment: Assignment 6 - Binary Search Tree
// @description: BinaryTree implementation file. Utilizes 3 different traversal methods
//				 and copy and destroy methods.

#include "BinaryTree.h"
#include <iostream>
#include <cstddef>
using namespace std;

BinaryTree::BinaryTree()
{
	mroot = NULL;
}

BinaryTree::BinaryTree(const ItemType &rootItem)
{
	mroot = new Node(rootItem, NULL, NULL);
}

BinaryTree::BinaryTree(const ItemType &rootItem, BinaryTree &leftTree, BinaryTree &rightTree)
{
	mroot = new Node(rootItem, leftTree.mroot, rightTree.mroot);
}

BinaryTree::~BinaryTree()
{
	destroyTree(mroot);
	mroot = NULL;
}

bool BinaryTree::isEmpty() const
{
	return (mroot == NULL);
}

void BinaryTree::preorderTraverse() const
{
	// Root -> Left -> Right
	preorder(mroot);
	cout << endl;
}

void BinaryTree::inorderTraverse() const
{
	// Left -> Root -> Right
	inorder(mroot);
	cout << endl;
}

void BinaryTree::postorderTraverse() const
{
	// Left -> Right -> Root
	postorder(mroot);
	cout << endl;
}

void BinaryTree::copyTree(Node* &newtreep, Node* oldtreep)
{
	if (newtreep != NULL)
	{
		destroyTree(newtreep);
	}
	if (oldtreep == NULL)
	{
		newtreep = NULL;
	}
	else
	{
		newtreep = new Node(oldtreep -> mitem, NULL, NULL);
		copyTree(newtreep -> mleftptr, oldtreep -> mleftptr);
		copyTree(newtreep -> mrightptr, oldtreep -> mrightptr);
	}
}

void BinaryTree::destroyTree(Node* &treep)
{	
	if (treep != NULL)
	{
		destroyTree(treep -> mleftptr); // Traverse left
		destroyTree(treep -> mrightptr); // Travers right
		delete treep; // delete node
		treep = NULL; // secure old data
	}
}

void BinaryTree::preorder(Node* treep) const
{
	if (treep == NULL)
	{
		return;
	}
	
	cout << treep -> mitem << " "; // Display root
	preorder(treep -> mleftptr); // Recur on left subtree
	preorder(treep -> mrightptr); // Recur on right subtree
}

void BinaryTree::inorder(Node* treep) const
{
	if (treep == NULL)
	{
		return;
	}
	
	inorder(treep -> mleftptr); // Recur on left subtree
	cout << treep -> mitem << " "; // Print data
	inorder(treep -> mrightptr); // Recur on right subtree
}

void BinaryTree::postorder(Node* treep) const
{
	if (treep == NULL)
	{
		return;
	}
	
	postorder(treep -> mleftptr); // Recur on left subtree
	postorder(treep -> mrightptr); // Recur on right subtree
	cout << treep -> mitem << " "; // Print data
}