/** @file Node.h */

#ifndef NODE_
#define NODE_

#include <memory>

template<class ItemType>
class Node
{
private:
	ItemType item;
	std::shared_ptr<Node<ItemType>> next;
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr);
	ItemType getItem() const;
	auto getNext() const;
};

#include "Node.cpp"
#endif
