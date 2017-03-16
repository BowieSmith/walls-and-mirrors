#include <iostream>
#include "ListQueue.h"

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
	ListQueue<int> intQueue;

	for (int i = 1; i < 20; i += 3)
	{
		intQueue.enqueue(i);
	}
	displayQueue(intQueue);

	std::cout << "\n\n";

	auto copiedIntQueue(intQueue);
	copiedIntQueue.enqueue(99);

	displayQueue(copiedIntQueue);

	return 0;
}
