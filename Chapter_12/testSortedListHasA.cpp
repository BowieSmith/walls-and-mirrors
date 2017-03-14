#include "SortedListHasA.h"
#include <iostream>
#include <string>

template<class ItemType>
void display(const SortedListInterface<ItemType>& aList)
{   
	for (int i = 1; i <= aList.getLength(); i++)
	{   
		std::cout << aList.getEntry(i) << ", ";
	}
}

template<class ItemType>
void test(const SortedListInterface<ItemType>& aList)
{
	std::cout << "Is empty: " << aList.isEmpty() << "\n"
		<< "Length: " << aList.getLength() << "\n"
		<< "Contents: ";
	display(aList);
	std::cout << "\n\n";
}

int main()
{
	SortedListHasA<std::string> stringSortedList;
	stringSortedList.insertSorted("Jenny");
	stringSortedList.insertSorted("Bowie");
	stringSortedList.insertSorted("Lisa");
	stringSortedList.insertSorted("Christy");
	test(stringSortedList);

	stringSortedList.removeSorted("Jenny");
	test(stringSortedList);

	int christyPos = stringSortedList.getPosition("Christy");
	std::cout << "Christy at position: " << christyPos << "\n";
	int amyPos = stringSortedList.getPosition("Amy");
	std::cout << "Amy at position: " << amyPos << "\n";
	int zedPos = stringSortedList.getPosition("Zed");
	std::cout << "Zed at position: " << zedPos << "\n\n";

	stringSortedList.removeSorted("Christy");
	test(stringSortedList);

	stringSortedList.clear();
	test(stringSortedList);

	return 0;
}

