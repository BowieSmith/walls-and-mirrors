/** Implementation file for the class ArrayBag.
	@file ArrayBag.cpp */

#include "ArrayBag.h"

template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	int result = -1;
	int searchIndex = 0;

	while ((result == -1) && (searchIndex < itemCount))
	{
		if (items[searchIndex] == target)
		{
			result = searchIndex;
		}
		else
		{
			searchIndex++;
		}
	}
	return result;
}

template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newItem)
{
	if (itemCount >= maxItems)
		return false;
	else
	{
		items[itemCount] = newItem;
		itemCount++;
		return true;
	}
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	bool result = false;
	int position = getIndexOf(anEntry);
	if (position >= 0)
	{
		result = true;
		itemCount--;
		items[position] = items[itemCount];
	}
	return result;
}

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) >= 0;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int curIndex = 0;
	while (curIndex < itemCount)
	{
		if (items[curIndex] == anEntry)
		{
			frequency++;
		}

		curIndex++;
	}

	return frequency;
}

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
	return bagContents;
}
