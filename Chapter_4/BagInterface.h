/** @file BagInterface.h */

#ifndef BAG_INTERFACE_
#define BAG_INTERFACE_

#include <vector>

template<class ItemType>
class BagInterface
{
public:
	virtual int getCurrentSize() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool add(const ItemType& newEntry) = 0;
	virtual bool remove(const ItemType& anEntry) = 0;
	virtual void clear() = 0;
	virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
	virtual bool contains(const ItemType& anEntry) const = 0;
	virtual std::vector<ItemType> toVector() const = 0;
	virtual ~BagInterface() { }
};

#endif
