/** ADT queue: Link-based implementation
 * @file LinkedQueue.h
 */

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "QueueInterface.h"
#include "../Chapter_9/Node.h"
#include "../Chapter_9/PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
	std::shared_ptr<Node<ItemType>> frontPtr;
	std::shared_ptr<Node<ItemType>> backPtr;

public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue<ItemType>& aQueue);
	~LinkedQueue();

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const throw(PrecondViolatedExcept);
};

#include "LinkedQueue.cpp"
#endif
