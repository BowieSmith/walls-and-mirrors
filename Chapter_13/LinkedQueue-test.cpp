#include <iostream>
#include "LinkedQueue.h"

template<class ItemType>
void displayQueue(QueueInterface<ItemType>& aQueue)
{
	while (!aQueue.isEmpty())
	{
		std::cout << aQueue.peekFront() << " ";
		aQueue.dequeue();
	}
}

int main()
{
	LinkedQueue<int> intQueue;

	for (int i = 1; i < 20; i += 3)
	{
		intQueue.enqueue(i);
	}
	auto copiedIntQueue(intQueue);

	displayQueue(intQueue);

	std::cout << "\n\n";

	copiedIntQueue.enqueue(99);

	displayQueue(copiedIntQueue);

	return 0;
}
