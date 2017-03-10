/** @file Node.cpp */

#include "Node.h"

template<class ItemType>
Node<ItemType>::Node()
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem)
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem,
					 std::shared_ptr<Node<ItemType>> nextNodePtr)
					 : next(nextNodePtr), item(anItem)
{
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType>> nextNodePtr)
{
	next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

template<class ItemType>
auto Node<ItemType>::getNext() const
{
	return next;
}
