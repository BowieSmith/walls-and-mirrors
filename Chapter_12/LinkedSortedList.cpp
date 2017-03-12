/** @file LinkedSortedList.cpp */

#include "LinkedSortedList.h"

template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	auto curPtr = headPtr;
	std::shared_ptr<Node<ItemType>> prevPtr;

	while (curPtr != nullptr && anEntry > curPtr->getItem())
	{
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	}

	return prevPtr;
}

template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeAt(int position) const
{
	auto curPtr = headPtr;
	for (int i = 1; i < position; i++)
	{
		curPtr = curPtr->getNext();
	}
	return curPtr;
}

template<class ItemType>
auto LinkedSortedList<ItemType>::copyChain(
		const std::shared_ptr<Node<ItemType>>& origChainPtr)
{
	std::shared_ptr<Node<ItemType>> copiedChainPtr;
	if (origChainPtr != nullptr)
	{
		copiedChainPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem());
		copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
	}
	return copiedChainPtr;
}

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : itemCount(0)
{
}

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(
		const LinkedSortedList<ItemType>& aList)
{
	headPtr = copyChain(aList.headPtr);
	itemCount = aList.itemCount;
}

template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
	clear();
}

template<class ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
	auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry);
	auto prevPtr = getNodeBefore(newEntry);

	if (isEmpty() || (prevPtr == nullptr))
	{
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	}
	else
	{
		auto afterPtr = prevPtr->getNext();
		newNodePtr->setNext(afterPtr);
		prevPtr->setNext(newNodePtr);
	}

	itemCount++;
	return true;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
	auto prevNode = getNodeBefore(anEntry);
	bool canRemove = (prevNode != nullptr);

	if (canRemove)
	{
		prevNode->setNext(prevNode->getNext()->getNext());
		itemCount--;
	}
	return canRemove;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry) const
{
	auto currentNode = headPtr;
	ItemType currentItem;

	int position = 1;
	bool lessThanOthers = true;

	while (lessThanOthers && currentNode != nullptr)
	{
		currentItem = currentNode->getItem();

		if (currentItem < anEntry)
		{
			position++;
			currentNode = currentNode->getNext();
		}
		else if (currentItem == anEntry)
		{
			lessThanOthers = false;
		}
		else
		{
			lessThanOthers = false;
			position = position * (-1);
		}
	}

	if (currentNode == nullptr)
	{
		if (anEntry >= currentItem)
		{
			position = position * (-1);
		}
	}
	return position;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
	return headPtr == nullptr;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
	return itemCount;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
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
void LinkedSortedList<ItemType>::clear()
{
	headPtr = nullptr;
	itemCount = 0;
}


template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept)
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
