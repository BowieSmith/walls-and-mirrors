#include "LinkedList.h"
#include <iostream>

template<class ItemType>
void display(const ListInterface<ItemType>& aList)
{
	for (int i = 1; i <= aList.getLength(); i++)
	{
		std::cout << aList.getEntry(i) << ", ";
	}
}

template<class ItemType>
void test(const ListInterface<ItemType>& aList)
{
	std::cout << "Is empty: " << aList.isEmpty() << "\n"
			  << "Length: " << aList.getLength() << "\n"
			  << "Contents: ";
	display(aList);
	std::cout << "\n\n";
}

int main()
{
	// LinkedList<int> intLinkedList;
	// test(intLinkedList);

	// intLinkedList.insert(1, 7);
	// intLinkedList.insert(2, 14);
	// intLinkedList.insert(3, 21);
	// test(intLinkedList);

	// intLinkedList.replace(2, 9);
	// test(intLinkedList);

	// intLinkedList.remove(2);
	// test(intLinkedList);

	// intLinkedList.clear();
	// test(intLinkedList);

	int intArray[] = {0, 1, 1, 2, 3, 5, 8, 13};
	LinkedList<int> intLinkedList(8, intArray);
	test(intLinkedList);

	intLinkedList.insert(1, 1);
	test(intLinkedList);

	intLinkedList.insert(10, 1);
	test(intLinkedList);

	LinkedList<int> copiedList(intLinkedList);
	test(copiedList);

	return 0;
}
