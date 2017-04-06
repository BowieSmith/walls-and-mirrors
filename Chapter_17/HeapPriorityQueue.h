/** ADT priority queue: Heap-based implementation
@file HeapPriorityQueue.h
*/

#ifndef HEAP_PRIORITY_QUEUE
#define HEAP_PRIORITY_QUEUE

#include "ArrayMaxHeap.h"
#include "PriorityQueueInterface.h"

template<class ItemType>
class HeapPriorityQueue : public PriorityQueueInterface<ItemType>,
						  private ArrayMaxHeap<ItemType>
{
public:
	HeapPriorityQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const throw(PrecondViolatedExcept);
};

#include "HeapPriorityQueue.cpp"
#endif