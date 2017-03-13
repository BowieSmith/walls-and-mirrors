/** ADT sorted list using the ADT list
	@file SortedListHasA.h
*/

#ifndef SORTED_LIST_HAS_A_
#define SORTED_LIST_HAS_A_

#include <memory>
#include "SortedListInterface.h"
#include "../Chapter_9/ListInterface.h"
#include "../Chapter_9/Node.h"
#include "../Chapter_9/PrecondViolatedExcept.h"

template<class ItemType>
class SortedListHasA : public SortedListInterface<ItemType>
{
private:
	std::unique_ptr<ListInterface<ItemType>> listPtr;

public:
	SortedListHasA();
	SortedListHasA(const SortedListHasA<ItemType>& sList);
	virtual ~SortedListHasA();

	bool insertSorted(const ItemType& newEntry);
	bool removeSorted(const ItemType& anEntry);
	int getPosition(const ItemType& anEntry) const;

	bool isEmpty() const;
	int getLength() const;
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const throw(PrecondViolatedExcept);
};

#include "SortedListHasA.cpp"
#endif