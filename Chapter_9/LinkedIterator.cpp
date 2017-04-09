/**
 * @file LinkedIterator.cpp
 */

#include "LinkedIterator.h"

template<class ItemType>
LinkedIterator<ItemType>::LinkedIterator(std::shared_ptr<LinkedList<ItemType>> someList,
										 std::shared_ptr<Node<ItemType>> nodePtr)
							: containerPtr(someList), currentItemPtr(nodePtr)
{
}

template<class ItemType>
const ItemType LinkedIterator<ItemType>::operator*()
{
	return currentItemPtr->getItem();
}

template<class ItemType>
LinkedIterator<ItemType> LinkedIterator<ItemType>::operator++()
{
	currentItemPtr = currentItemPtr->getNext();
	return *this;
}

template<class ItemType>
bool LinkedIterator<ItemType>::operator==(const LinkedIterator<ItemType>& rightHandSide) const
{
	return ((containerPtr == rightHandSide.containerPtr) &&
			(currentItemPtr == rightHandSide.currentItemPtr));
}

template<class ItemType>
bool LinkedIterator<ItemType>::operator!=(const LinkedIterator<ItemType>& rightHandSide) const
{
	return ((containerPtr != rightHandSide.containerPtr) ||
			(currentItemPtr != rightHandSide.currentItemPtr));
}
