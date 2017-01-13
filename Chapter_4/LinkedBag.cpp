#include "LinkedBag.h"
#include <iostream>

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const ItemType itemArray[], int arraySize)
								: headPtr(nullptr), itemCount(0)
{
	for (int i = 0; i < arraySize; i++)
	{
		add(itemArray[i]);
	}
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
	Node<ItemType>* origChainPtr = aBag.headPtr;
	if (origChainPtr == nullptr)
	{
		headPtr = nullptr;
	}
	else
	{
		headPtr = new Node<ItemType>(origChainPtr->getItem());

		Node<ItemType>* newChainPtr = headPtr;
		origChainPtr = origChainPtr->getNext();

		while (origChainPtr != nullptr)
		{
			Node<ItemType>* newNodePtr = new Node<ItemType>(origChainPtr->getItem());
			newChainPtr->setNext(newNodePtr);

			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		}
		newChainPtr->setNext(nullptr);
	}
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
	clear();
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target) const
{
	Node<ItemType>* curPtr = headPtr;
	bool found = false;
	while (!found && (curPtr != nullptr))
	{
		if (curPtr->getItem() == target)
		{
			found = true;
		}
		else
		{
			curPtr = curPtr->getNext();
		}
	}
	return curPtr;
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
	headPtr = new Node<ItemType>(newEntry, headPtr);
	itemCount++;

	return true;
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	Node<ItemType>* nodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (nodePtr != nullptr);
	if (canRemoveItem)
	{
		nodePtr->setItem(headPtr->getItem());
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		itemCount--;
	}
	return canRemoveItem;
}

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr)
	{
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = headPtr;
	}
	itemCount = 0;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int total = 0;
	Node<ItemType>* currentPointer = headPtr;

	for (int i = 0; i < itemCount; i++)
	{
		if (currentPointer->getItem() == anEntry)
		{
			total += 1;
		}
		currentPointer = currentPointer->getNext();
	}
	return total;
}

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
	std::vector<ItemType> vec;

	Node<ItemType>* currentPointer = headPtr;

	for (int i = 0; i < itemCount; i++)
	{
		vec.push_back(currentPointer->getItem());
		currentPointer = currentPointer->getNext();
	}

	return vec;
}

template<class ItemType>
void LinkedBag<ItemType>::displayContents() const
{
	Node<ItemType>* curPtr = headPtr;

	for (int i = 0; i < itemCount; i++)
	{
		std::cout << curPtr->getItem() << " ";
		curPtr = curPtr->getNext();
	}
	std::cout << std::endl;
}
