/** @file Node.cpp */

#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : next(nullptr), item(anItem)
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr)
						: next(nextNodePtr), item(anItem)
{
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}
