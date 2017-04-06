#include "HeapPriorityQueue.h"
#include "ArrayMaxHeap.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	HeapPriorityQueue<int> intPriorityQueue;
	int rand;

	for (int i = 0; i < 10; i++)
	{
		rand = std::rand();
		std::cout << "System Time: " << rand << std::endl;
		rand = rand % 100;
		std::cout << "Random Number (% 100): " << rand << std::endl;
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
