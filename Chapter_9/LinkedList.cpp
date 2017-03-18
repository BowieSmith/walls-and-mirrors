#include "LinkedList.h"
#include <cassert>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : itemCount(0)
{
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(int arraySize, const ItemType itemArray[])
{
	if (arraySize <= 0)
	{
		itemCount = 0;
	}
	else
	{
		itemCount = arraySize;
		headPtr = std::make_shared<Node<ItemType>>(itemArray[0]);
		std::shared_ptr<Node<ItemType>> thisChain = headPtr;

		for (int i = 1; i < arraySize; i++)
		{
			thisChain->setNext(std::make_shared<Node<ItemType>>(itemArray[i]));
			thisChain = thisChain->getNext();
		}
		thisChain->setNext(nullptr);
	}
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
	itemCount = aList.getLength();

	if (aList.headPtr != nullptr)
	{
		headPtr = std::make_shared<Node<ItemType>>(aList.headPtr->getItem());

		auto thisChain = headPtr;
		auto otherChain = aList.headPtr->getNext();

		while (otherChain != nullptr)
		{
			thisChain->setNext(std::make_shared<Node<ItemType>>(otherChain->getItem()));
			thisChain = thisChain->getNext();
			otherChain = otherChain->getNext();
		}
		thisChain->setNext(nullptr);
	}
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}

template<class ItemType>
auto LinkedList<ItemType>::getNodeAt(int position) const
{
	assert( (position >= 1) && (position <= itemCount) );

	auto currentNode = headPtr;
	for (int i = 1; i < position; i++)
	{
		currentNode = currentNode->getNext();
	}
	return currentNode;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	bool canInsert = (newPosition >= 1) && (newPosition <= (itemCount + 1));
	if (canInsert)
	{
		auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry);

		if (newPosition == 1)
		{
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			auto prevPtr = getNodeAt(newPosition - 1);
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}
		itemCount++;
	}
	return canInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool canRemove = (position >= 1) && (position <= itemCount);
	if (canRemove)
	{
		if (position == 1)
		{
			headPtr = headPtr->getNext();
		}
		else
		{
			auto prevPtr = getNodeAt(position - 1);
			auto curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
		}
		itemCount--;
	}

	return canRemove;
}

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	headPtr = nullptr;
	itemCount = 0;
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept)
{
	bool canGetEntry = (position >= 1) && (position <= itemCount);
	if (canGetEntry)
	{
		return getNodeAt(position)->getItem();
	}
	else
	{
		throw PrecondViolatedExcept("getEntry() called with empty list on invalid position");
	}
}

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept)
{
	bool canReplace = (position >= 1) && (position <= itemCount);
	if (canReplace)
	{
		auto itemNode = getNodeAt(position);
		ItemType replacedItem = itemNode->getItem();
		itemNode->setItem(newEntry);
		return replacedItem;
	}
	else
	{
		throw PrecondViolatedExcept("replace() called with empty list on invalid position");
	}
}

template<class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType>& rightOperand) const
{
	bool isEqual = true; // assume equal
	
	if (itemCount != rightOperand.getLength())
	{
		isEqual = false;
	}
	else
	{
		auto leftSidePtr = headPtr;
		auto rightSidePtr = rightOperand.headPtr;

		while ((leftSidePtr != nullptr) && (rightSidePtr != nullptr) && isEqual)
		{
			isEqual =  (leftSidePtr->getItem() == rightSidePtr->getItem());
			leftSidePtr = leftSidePtr->getNext();
			rightSidePtr = rightSidePtr->getNext();
		}
	}
	return isEqual;
}
