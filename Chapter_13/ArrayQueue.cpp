/** ADT Queue: Array-based implementation
 * @file ArrayQueue.cpp
 */

#include "ArrayQueue.h"

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue()
					: front(0), back(DEFALT_CAPACITY - 1), count(0)
{
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
	return count == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	bool canEnqueue= (count < DEFALT_CAPACITY);
	if (canEnqueue)
	{
		back = (back + 1) % DEFALT_CAPACITY;
		items[back] = newEntry;
		count++;
	}
	
	return canEnqueue;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue()
{
	bool canDequeue = (count > 0);
	if (canDequeue)
	{
		front = (front + 1) % DEFALT_CAPACITY;
		count--;
	}

	return canDequeue;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept)
{
	if (count <= 0)
	{
		throw PrecondViolatedExcept("peekFront() called on empty queue");
	}

	return items[front];
}
