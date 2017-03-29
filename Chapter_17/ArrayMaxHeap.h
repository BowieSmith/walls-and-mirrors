/** Array-based implementation of the ADT Heap.
@file ArrayMaxHeap.h */

#ifndef ARRAY_MAX_HEAP_
#define ARRAY_MAX_HEAP_

#include "HeapInterface.h"
#include "../Chapter_9/PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>
{
private:
	static const int ROOT_INDEX = 0;
	static const int DEFAULT_CAPACITY = 21;
	std::unique_ptr<ItemType[]> items;
	int itemCount;
	int maxItems;

	int getLeftChildIndex(const int nodeIndex) const;
	int getRightChildIndex(const int nodeIndex) const;
	int getParentIndex(const int nodeIndex) const;
	bool isLeaf(const int nodeIndex) const;
	void heapRebuild(int nodeIndex);  // Converts semiheap to heap
	void heapCreate();

public:
	ArrayMaxHeap();
	ArrayMaxHeap(const ItemType someArray[], const int arraySize);
	virtual ~ArrayMaxHeap();

	bool isEmpty() const;
	int getNumberOfNodes() const;
	int getHeight() const;
	ItemType peekTop() const throw(PrecondViolatedExcept);
	bool add(const ItemType& newData);
	bool remove();
	void clear();
};

#include "ArrayMaxHeap.cpp"
#endif