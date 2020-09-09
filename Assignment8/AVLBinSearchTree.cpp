// @author: Alex Banning
// @filename: AVLBinSearchTree.cpp
// @date: April 30th, 2019
// @assignment: Assignment 8 - AVL Binary Search Tree
// @description: AVL Binary Search Tree implentation file

#include "AVLBinSearchTree.h"

SearchPath::SearchPath()
{
    size = 0;
    pivotIndex = -1;
    for(int i = 0; i < MAXHEIGHT; i++) 
	{
		path[i] = NULL;
	}
}

AVLBinSearchTree::AVLBinSearchTree()
{
}

AVLBinSearchTree::AVLBinSearchTree(const AVLBinSearchTree &rhsTree)
{
	mroot = NULL;
	copyTree(mroot, rhsTree.mroot);
}

AVLBinSearchTree::~AVLBinSearchTree()
{
}

AVLBinSearchTree& AVLBinSearchTree::operator=(const AVLBinSearchTree &rhsTree)
{
	mroot = NULL;
	copyTree(mroot, rhsTree.mroot);
	return *this;
}

void AVLBinSearchTree::addNewEntryAndMakeSearchPath(const ItemType &newItem, Node* &treeptr, SearchPath &search)
{
	if (treeptr != NULL)
	{
		search.path[search.size] = treeptr;
		search.size += 1;
		
		if (newItem == treeptr -> mitem)
		{
			cout << "That item is already in the BST." << endl;
		}
		else if (newItem <= treeptr -> mitem)
		{
			addNewEntryAndMakeSearchPath(newItem, treeptr -> mleftptr, search);
		}
		else
		{
			addNewEntryAndMakeSearchPath(newItem, treeptr -> mrightptr, search);
		}
	}
	else
	{
		treeptr = new Node(newItem, NULL, NULL);
		search.path[search.size] = treeptr;
		search.size += 1;
	}
	
	if (treeptr == NULL)
	{
		cout << "Memory is full." << endl;
	}
}

bool AVLBinSearchTree::hasNoPivot(SearchPath &search)
{
	int index = search.size - 1;
	while (index >= 0)
	{
		if (search.path[index] -> mheight != 0)
		{
			search.pivotIndex = index;
			return false;
		}
		index--;
	}
	
	return true;
}

void AVLBinSearchTree::fixBalances(const SearchPath &search, int start)
{
	for (int i = start; i < search.size - 1; ++i)
	{
		if (search.path[i] -> mrightptr == search.path[i + 1])
		{
			search.path[i] -> mheight++;
		}
		else
		{
			search.path[i] -> mheight--;
		}
	}
}

bool AVLBinSearchTree::isAddedToShortSide(const SearchPath &search)
{
	return ((search.path[search.pivotIndex] -> mheight == -1 && search.path[search.pivotIndex + 1] == search.path[search.pivotIndex] -> mrightptr)
			||(search.path[search.pivotIndex] -> mheight ==  1 && search.path[search.pivotIndex + 1] == search.path[search.pivotIndex] -> mleftptr));
}

bool AVLBinSearchTree::isSingleRotateRight(const SearchPath &search)
{
	return ((search.path[search.pivotIndex + 1] == search.path[search.pivotIndex] -> mleftptr) && 
				(search.path[search.pivotIndex + 2] == search.path[search.pivotIndex + 1] -> mleftptr));
}

bool AVLBinSearchTree::isSingleRotateLeft(const SearchPath &search)
{
	return ((search.path[search.pivotIndex] -> mrightptr == search.path[search.pivotIndex + 1]) && 
				(search.path[search.pivotIndex] -> mrightptr -> mrightptr == search.path[search.pivotIndex + 2]));
}

bool AVLBinSearchTree::isDoubleRotateLeftRight(const SearchPath &search)
{
	if (search.path[search.pivotIndex] -> mleftptr == search.path[search.pivotIndex + 1])
	{
		if(search.path[search.pivotIndex + 1] -> mrightptr == search.path[search.pivotIndex + 2])
			return true;
	}
	return false;
}

Node* AVLBinSearchTree::doSingleRotateLeft(SearchPath &search)
{
	Node* cloud = search.path[search.pivotIndex - 1];
	Node* pivot = search.path[search.pivotIndex];
	Node* pivotChild = search.path[search.pivotIndex + 1];
	Node* treeOne = pivot -> mleftptr;
	Node* treeTwo = pivotChild -> mleftptr;
	Node* treeThree = pivotChild -> mrightptr;
	pivotChild -> mrightptr = treeThree;
	pivotChild -> mleftptr = pivot;
	pivot -> mleftptr = treeOne;
	pivot -> mrightptr = treeTwo;
	
	if (search.pivotIndex == 0)
	{
		search.path[0] = pivotChild;
	}
	else if (cloud -> mrightptr == pivot)
	{
		cloud -> mrightptr = pivotChild;
	}
	else 
	{
		cloud -> mleftptr = pivotChild;
	}
	pivotChild -> mheight = 0;
	pivot -> mheight = 0;
	return search.path[0];
}

Node* AVLBinSearchTree::doSingleRotateRight(SearchPath &search)
{
	Node* cloud = search.path[search.pivotIndex - 1];
    Node* pivot = search.path[search.pivotIndex];
    Node* pivotChild = search.path[search.pivotIndex + 1];
    Node* treeOne = pivot -> mrightptr;
    Node* treeTwo = pivotChild -> mrightptr;
    Node* treeThree = pivotChild -> mleftptr;
	pivotChild -> mleftptr = treeThree;
    pivotChild -> mrightptr = pivot;
    pivot -> mrightptr = treeOne;
    pivot -> mleftptr = treeTwo;

    if (search.pivotIndex == 0)
    {
        search.path[0] = pivotChild;
    }
    else if (cloud -> mrightptr == pivot)
    {
        cloud -> mrightptr = pivotChild;
    }
    else
    {
        cloud -> mleftptr = pivotChild;
    }
	pivotChild -> mheight = 0;
    pivot -> mheight = 0;
	return search.path[0];
}

Node* AVLBinSearchTree::doDoubleRotateLeftRight(SearchPath &search)
{
    Node* cloud = search.path[search.pivotIndex - 1];
    Node* pivot = search.path[search.pivotIndex];
	Node* pivotChild = search.path[search.pivotIndex + 1];
    Node* grandChild = search.path[search.pivotIndex + 2];
    Node* treeOne = pivotChild -> mleftptr;
    Node* treeTwo = grandChild -> mleftptr;
    Node* treeThree = grandChild -> mrightptr;
    Node* treeFour = pivot -> mrightptr;
	bool mleftptr = search.path[search.size - 2] -> mleftptr == search.path[search.size - 1];
	grandChild -> mleftptr = pivotChild;
    grandChild -> mrightptr = pivot;
    pivotChild -> mleftptr = treeOne;
    pivotChild -> mrightptr = treeTwo;
    pivot -> mleftptr = treeThree;
    pivot -> mrightptr = treeFour;
    grandChild -> mheight = 0;
	if (search.pivotIndex == 0)
    {
        search.path[0] = grandChild;
    }
    else if (cloud -> mrightptr == pivot)
    {
        cloud -> mrightptr = grandChild;
    }
    else
    {
        cloud -> mleftptr = grandChild;
    }
	if (mleftptr)
    {
        pivot -> mheight = 1;
        pivotChild -> mheight = 0;
    }
    else
    {
        pivot -> mheight = 0;
        pivotChild -> mheight = 1;
    }
    search.path[search.size - 2] -> mheight = 0;
	return search.path[0];
}

Node* AVLBinSearchTree::doDoubleRotateRightLeft(SearchPath &search)
{
    Node *cloud = search.path[search.pivotIndex - 1];
    Node *pivot = search.path[search.pivotIndex];
    Node *pivotChild = search.path[search.pivotIndex + 1];
    Node *grandChild = search.path[search.pivotIndex + 2];
    Node *T1 = pivotChild -> mrightptr;
    Node *T2 = grandChild -> mrightptr;
    Node *T3 = grandChild -> mleftptr;
    Node *T4 = pivot -> mleftptr;

    bool mleftptr = search.path[search.size - 2] -> mleftptr == search.path[search.size - 1];

    grandChild -> mrightptr = pivotChild;
    grandChild -> mleftptr = pivot;
    pivotChild -> mrightptr = T1;
    pivotChild -> mleftptr = T2;
    pivot -> mrightptr = T3;
    pivot -> mleftptr = T4;
    grandChild -> mheight = 0;

    if (search.pivotIndex == 0)
    {
        search.path[0] = grandChild;
    }
    else if (cloud -> mrightptr == pivot)
    {
        cloud -> mrightptr = grandChild;
    }
    else
    {
        cloud -> mleftptr = grandChild;
    }

    if (mleftptr)
    {
        pivot -> mheight = 0;
        pivotChild -> mheight = 1;
    }
    else
    {
        pivot -> mheight = 1;
        pivotChild -> mheight = 0;
    }
    search.path[search.size - 2] -> mheight = 0;

    return search.path[0];
}

void AVLBinSearchTree::Insert(const ItemType &newItem)
{
   SearchPath search;
   addNewEntryAndMakeSearchPath(newItem, mroot, search);
   int searchIndex = 0;
   
   if(hasNoPivot(search))
   {
	   fixBalances(search, 0);
   }
   else if (isAddedToShortSide(search))
   {
	   searchIndex = search.pivotIndex;
	   fixBalances(search, searchIndex);
   }
   else if (isSingleRotateLeft(search))
   {
	   mroot = doSingleRotateLeft(search);
	   fixBalances(search, search.pivotIndex + 2);
   }
   else if (isSingleRotateRight(search))
   {
	   mroot = doSingleRotateRight(search);
	   fixBalances(search, search.pivotIndex + 2);
   }
   else if (isDoubleRotateLeftRight(search))
   {
	   mroot = doDoubleRotateLeftRight(search);
	   fixBalances(search, search.pivotIndex + 3);
   }
   else
   {
	   mroot = doDoubleRotateRightLeft(search);
	   fixBalances(search, search.pivotIndex + 3);
   }
}