/** Implementation of ADT Heap.
@file ArrayMaxHeap.cpp */

#include "ArrayMaxHeap.h"
#include <algorithm>
#include <cmath>

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
	return (2 * nodeIndex) + 1;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
	return (2 * nodeIndex) + 2;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
	return (nodeIndex - 1) / 2;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(const int nodeIndex) const
{
	return ((nodeIndex * 2) + 1) > (itemCount - 1);
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int nodeIndex)
{
	if (!isLeaf(nodeIndex))
	{
		int leftChildIndex = getLeftChildIndex(nodeIndex);
		int rightChildIndex = getRightChildIndex(nodeIndex);
		int largerChildIndex = rightChildIndex;		// Assume right child larger

		if ((largerChildIndex >= itemCount) || (items[leftChildIndex] > items[rightChildIndex]))
		{
			largerChildIndex = leftChildIndex;
		}

		if (items[nodeIndex] < items[largerChildIndex])
		{
			std::swap(items[nodeIndex],items[largerChildIndex]);
			heapRebuild(largerChildIndex);
		}
	}
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
	for (int index = itemCount / 2 - 1; index >= 0; index--)
	{
		heapRebuild(index);
	}
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize)
							: itemCount(arraySize), maxItems(2 * arraySize)
{
	items = std::make_unique<ItemType[]>(maxItems);
	for (int i = 0; i < itemCount; i++)
	{
		items[i] = someArray[i];
	}
	heapCreate();
}

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{
	clear();
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
	return itemCount <= 0;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
	return itemCount;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
	return std::floor(std::log2(itemCount));
}

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw(PrecondViolatedExcept)
{
	if (isEmpty())
	{
		throw PrecondViolatedExcept("Attempted peek into an empty heap.");
	}
	return items[0];
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newItem)
{
	items[itemCount] = newItem;

	int newItemIndex = itemCount;
	bool inPlace = false;

	while ((newItemIndex >= 0) && !inPlace)
	{
		int parentIndex = getParentIndex(newItemIndex);
		if (items[newItemIndex] <= items[parentIndex])
		{
			inPlace = true;
		}
		else
		{
			std::swap(items[newItemIndex], items[parentIndex]);
			newItemIndex = parentIndex;
		}
	}

	itemCount++;
	return inPlace;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
	bool canRemove = !isEmpty();
	if (canRemove)
	{
		items[0] = items[itemCount - 1];
		itemCount--;
		heapRebuild(0);
	}
	return canRemove;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
	itemCount = 0;
}