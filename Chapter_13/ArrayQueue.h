/** ADT queue: Array-based specification
 * @file ArrayQueue.h
 */

#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_

#include "QueueInterface.h"
#include "../Chapter_9/PrecondViolatedExcept.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
	static const int DEFALT_CAPACITY = 50;
	ItemType items[DEFALT_CAPACITY];
	int front;
	int back;
	int count;

public:
	ArrayQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const throw(PrecondViolatedExcept);
};

#include "ArrayQueue.cpp"
#endif
