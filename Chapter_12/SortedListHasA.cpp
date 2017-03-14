/** @file SortedListHasA.cpp */

#include "SortedListHasA.h"
#include "../Chapter_9/LinkedList.h"

template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA()
						  : listPtr(std::make_unique<LinkedList<ItemType>>())
{
}

template<class ItemType>
SortedListHasA<ItemType>::
		SortedListHasA(const SortedListHasA<ItemType>& sList)
						  : listPtr(std::make_unique<LinkedList<ItemType>>())
{
	for (int position = 1; position <= sList.getLength(); position++)
	{
		listPtr->insert(position, sList.getEntry(position));
	}
}

template<class ItemType>
SortedListHasA<ItemType>::~SortedListHasA()
{
	clear();
}

template<class ItemType>
bool SortedListHasA<ItemType>::insertSorted(const ItemType& newEntry)
{
	int newPosition = abs(getPosition(newEntry));
	return listPtr->insert(newPosition, newEntry);
}

template<class ItemType>
bool SortedListHasA<ItemType>::removeSorted(const ItemType& anEntry)
{
	int thePosition = getPosition(anEntry);
	return listPtr->remove(thePosition);
}

template<class ItemType>
int SortedListHasA<ItemType>::getPosition(const ItemType& anEntry) const
{
	int position = 1;
	bool lessThanOthers = true;
	ItemType currentItem;

	while (lessThanOthers && (position <= getLength()))
	{
		currentItem = getEntry(position);

		if (currentItem < anEntry)
		{
			position++;
		}
		else if (currentItem == anEntry)
		{
			lessThanOthers = false;
		}
		else
		{
			lessThanOthers = false;
			position = position * (-1);
		}
	}

	if (position > getLength())
	{
		position = position * (-1);
	}

	return position;
}

template<class ItemType>
bool SortedListHasA<ItemType>::isEmpty() const
{
	return listPtr->isEmpty();
}

template<class ItemType>
int SortedListHasA<ItemType>::getLength() const
{
	return listPtr->getLength();
}

template<class ItemType>
bool SortedListHasA<ItemType>::remove(int position)
{
	return listPtr->remove(position);
}

template<class ItemType>
void SortedListHasA<ItemType>::clear()
{
	listPtr->clear();
}

template<class ItemType>
ItemType SortedListHasA<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept)
{
	return listPtr->getEntry(position);
}
