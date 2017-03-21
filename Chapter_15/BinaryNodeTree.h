/** ADT binary tree: Link-based implementation.
@file BinaryNodeTree.h
*/

#ifndef BINARY_NODE_TREE
#define BINARY_NODE_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "../Chapter_9/PrecondViolatedExcept.h"
#include "NotFoundException.h"
#include <memory>

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
	std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
	int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
	int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
	auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
					 std::shared_ptr<BinaryNode<ItemType>> newNodePtr);
	virtual auto removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
							 const ItemType& target, bool& isSuccessful);
	auto moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
	virtual auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
						  const ItemType& target, bool& isSuccessful) const;
	auto copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;
	void destryTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);
	void preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
	void inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
	void postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const;

public:
	BinaryNodeTree();
	BinaryNodeTree(const ItemType& rootItem);
	BinaryNodeTree(const ItemType& rootItem,
				   const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
				   const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
	BinaryNodeTree(const std::shared_ptr<BinaryNodeTree<ItemType>>& tree);
	virtual ~BinaryNodeTree();

	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw(PrecondViolatedExcept);
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newData);
	bool remove(const ItemType& data);
	void clear();
	ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
	bool contains(const ItemType& anEntry) const;

	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;

	BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
};

#include "BinaryNodeTree.cpp"
#endif