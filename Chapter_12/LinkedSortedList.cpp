/** @file LinkedSortedList.cpp */

#include "LinkedSortedList.h"

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
