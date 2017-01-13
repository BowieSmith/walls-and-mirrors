/** ADT bag: Link-based implementation.
 * @file LinkedBag.h */

#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;
	// Returns pointer to node containing entry or nullptr
	Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
	LinkedBag();
	LinkedBag(const ItemType itemArray[], int arraySize);
	LinkedBag(const LinkedBag<ItemType>& aBag);	// copy constructor
	virtual ~LinkedBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
	void displayContents() const;
};

#include "LinkedBag.cpp"
#endif
