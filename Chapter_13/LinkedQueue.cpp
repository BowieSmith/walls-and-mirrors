/** ADT Queue: Linked-Based implementation
 * @file LinkedQueue.cpp
 */

#include "LinkedQueue.h"

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
}

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType>& aQueue)
{
	if (!aQueue.isEmpty())
	{
		auto otherCurrentPtr = aQueue.frontPtr;

		frontPtr = std::make_shared<Node<ItemType>>(otherCurrentPtr->getItem());
		auto currentPtr = frontPtr;

		otherCurrentPtr = otherCurrentPtr->getNext();

		while (otherCurrentPtr != nullptr)
		{
			currentPtr->setNext(std::make_shared<Node<ItemType>>(otherCurrentPtr->getItem()));
			currentPtr = currentPtr->getNext();
			otherCurrentPtr = otherCurrentPtr->getNext();
		}

		backPtr = currentPtr;
	}
}

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	frontPtr = nullptr;
	backPtr = nullptr;
}

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
	return frontPtr == nullptr;
}

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry);

	if (isEmpty())
	{
		frontPtr = newNodePtr;
	}
	else
	{
		backPtr->setNext(newNodePtr);
	}
	backPtr = newNodePtr;

	return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool canRemove = !isEmpty();
	if (canRemove)
	{
		if (frontPtr->getNext() == nullptr)
		{
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else
		{
			frontPtr = frontPtr->getNext();
		}
	}
	return canRemove;
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept)
{
	if (isEmpty())
	{
		throw PrecondViolatedExcept("peekFront() called on empty Queue");
	}
	else
	{
		return frontPtr->getItem();
	}
}
