/** A class of nodes for a link-based binary tree.
@file BinaryNode.h
*/

#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

template<class memory>
class BinaryNode
{
private:
	ItemType item;
	std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;
	std::shared_ptr<BinaryNode<ItemType>> rightChildPtr;

public:
	BinaryNode();
	BinaryNode(const ItemType& anItem);
	BinaryNode(const ItemType& anItem,
			   std::shared_ptr<BinaryNode<Node>> leftPtr,
			   std::shared_ptr<BinaryNode<Node>> rightPtr);

	void setItem(const ItemType& anItem);
	ItemType getItem() const;

	bool isLeaf() const;

	auto getLeftChildPtr() const;
	auto getRightChildPtr() const;

	void setLeftChildPtr(std::shared_ptr<BinaryNode<Node>> leftPtr);
	void setRightChildPtr(std::shared_ptr<BinaryNode<Node>> rightPtr);
};

#include "BinaryNode.cpp"
#endif