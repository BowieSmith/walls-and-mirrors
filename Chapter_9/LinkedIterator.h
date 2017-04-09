/** Header file for LinkedIterator
 * @file LinkedIterator.h
 */

#ifndef LINKED_ITERATOR_
#define LINKED_ITERATOR_

#include <iterator>
#include "Node.h"

template<class ItemType>
class LinkedList;

template<class ItemType>
class LinkedIterator : public std::iterator<std::input_iterator_tag, int>
{
private:
	const std::shared_ptr<LinkedList<ItemType>> containerPtr;
	std::shared_ptr<Node<ItemType>> currentItemPtr;

public:
	LinkedIterator(std::shared_ptr<LinkedList<ItemType>> someList,
				   std::shared_ptr<Node<ItemType>> nodePtr = nullptr);
	const ItemType operator*();
	LinkedIterator<ItemType> operator++();
	bool operator==(const LinkedIterator<ItemType>& rightHandSide) const;
	bool operator!=(const LinkedIterator<ItemType>& rightHandSide) const;
};

#include "LinkedIterator.cpp"
#endif
