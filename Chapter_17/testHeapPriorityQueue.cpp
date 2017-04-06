#include "HeapPriorityQueue.h"
#include "ArrayMaxHeap.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
	ArrayMaxHeap<int> intMaxHeap;
	intMaxHeap.add(666);
	std::cout << intMaxHeap.peekTop();
	
	std::srand(std::time(NULL));
	HeapPriorityQueue<int> intPriorityQueue;
	int rand;
	
	std::cout << "Before loop!" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		std::cout << "Start loop!" << std::endl;
		rand = std::rand();
		intPriorityQueue.enqueue(rand);
	}

	while (!intPriorityQueue.isEmpty())
	{
		std::cout << "Start other loop!" << std::endl;
		std::cout << "IsEmpty(): " << intPriorityQueue.isEmpty() << std::endl;
		std::cout << intPriorityQueue.peekFront() << std::endl;
		intPriorityQueue.dequeue();
	}

	return 0;
}