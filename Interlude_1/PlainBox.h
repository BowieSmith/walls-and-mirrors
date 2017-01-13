/** @file PlainBox.h */

#ifndef PLAIN_BOX_
#define PLAIN_BOX_

template<class ItemType>
class PlainBox
{
private:
	ItemType item;

public:
	PlainBox();
	PlainBox(const ItemType& theItem);
	void setItem(const ItemType& theItem);
	ItemType getItem() const;
};

#include "PlainBox.cpp"
#endif
