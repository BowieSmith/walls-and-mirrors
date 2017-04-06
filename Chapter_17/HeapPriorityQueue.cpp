/** Heap-based implementation of the ADT Priority Queue
@file HeapPriorityQueue.cpp
*/

#include "HeapPriorityQueue.h"

template<class ItemType>
HeapPriorityQueue<ItemType>::HeapPriorityQueue()
{
}

template<class ItemType>
bool HeapPriorityQueue<ItemType>::isEmpty() const
{
	return ArrayMaxHeap<ItemType>::isEmpty();
}

template<class ItemType>
bool HeapPriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	return ArrayMaxHeap<ItemType>::add(newEntry);
}

template<class ItemType>
bool HeapPriorityQueue<ItemType>::dequeue()
{
	return ArrayMaxHeap<ItemType>::remove();
}

template<class ItemType>
ItemType HeapPriorityQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept)
{
	try
	{
		return ArrayMaxHeap<ItemType>::peekTop();
	}
	catch (PrecondViolatedExcept e)
	{
		throw PrecondViolatedExcept("Attempted peek into an empty priority queue.");
	}
}