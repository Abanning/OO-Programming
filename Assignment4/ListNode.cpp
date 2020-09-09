// @filename: ListNode.h
// @author: Alex Banning
// @assignment: Assignment 4 - Merge Sort
// @date: March 27th, 2019
// @description: Implemntation file for class ListNode

#include "ListNode.h"
#include <cstddef>


ListNode::ListNode()
{
	item = 0;
	next = NULL;
}

ListNode::ListNode(const ItemType &x)
{
	item = x;
	next = NULL;
}

ListNode::ListNode(const ItemType &x, ListNode* nNode)
{
	item = x;
	next = nNode;
}

ListNode::~ListNode()
{
}

ItemType ListNode::getItem()
{
	return item;
}

ListNode* ListNode::getNext()
{
	return next;
}

void ListNode::setItem(const ItemType &x)
{
	item = x;
}

void ListNode::setNext(ListNode* nNode)
{
	next = nNode;
}                                                                                  