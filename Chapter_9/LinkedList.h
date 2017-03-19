/** @file LinkedList.h */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
public:
	LinkedList();
	LinkedList(int arraySize, const ItemType itemArray[]);
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const throw(PrecondViolatedExcept);
	ItemType replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept);
	bool operator==(const LinkedList<ItemType>& rightOperand) const;
	LinkedList<ItemType>& operator=(const LinkedList<ItemType>& rightOperand);
	LinkedList<ItemType> operator+(const LinkedList<ItemType>& rightOperand) const;

	template<class friendItemType>
	friend std::ostream& operator<<(std::ostream& outputStream,
									const LinkedList<friendItemType>& outputList);

private:
	std::shared_ptr<Node<ItemType>> headPtr;
	int itemCount;
	auto getNodeAt(int position) const;
	void copyListNodes(const LinkedList<ItemType>& otherList);
};

#include "LinkedList.cpp"

#endif
