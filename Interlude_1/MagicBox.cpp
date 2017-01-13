/** MagicBox.cpp */

#include "MagicBox.h"

template<class ItemType>
MagicBox<ItemType>::MagicBox() : firstItemStored(false)
{
}

template<class ItemType>
MagicBox<ItemType>::MagicBox(const ItemType& theItem) :
                      PlainBox<ItemType>::PlainBox(theItem),
                      firstItemStored(true)
{
}

template<class ItemType>
void MagicBox<ItemType>::setItem(const ItemType& theItem)
{
  if (!firstItemStored)
  {
    PlainBox<ItemType>::setItem(theItem);
    firstItemStored = true;
  }
}
