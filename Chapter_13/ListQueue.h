/** ADT Queue: ADT List implementation
	@file ListQueue.h
*/

#ifndef LIST_QUEUE_
#define LIST_QUEUE_

#include "QueueInterface.h"
#include "../Chapter_9/PrecondViolatedExcept.h"
#include "../Chapter_9/LinkedList.h"
#include <memory>

template<class ItemType>
class ListQueue : public QueueInterface<ItemType>
{
private:
	std::unique_ptr<LinkedList<ItemType>> listPtr;

public:
	ListQueue();
	ListQueue(const ListQueue<ItemType>& aQueue);
	~ListQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const throw(PrecondViolatedExcept);
};

#include "ListQueue.cpp"
#endif