/** @file linkedBagTest.cpp */

#include <iostream>
#include "LinkedBag.h"

int main()
{
	LinkedBag<char> linkedCharBag;
	linkedCharBag.add('A');
	linkedCharBag.add('B');
	linkedCharBag.add('C');
	linkedCharBag.add('A');
	linkedCharBag.add('E');
	linkedCharBag.add('F');
	linkedCharBag.add('A');

	std::cout << "displayContents() produces: " << std::endl;
	linkedCharBag.displayContents();
	std::cout << std::endl;
	std::cout << "getFrequencyOf('A') returns: " << linkedCharBag.getFrequencyOf('A') << std::endl;
	std::cout << "getFrequencyOf('B') returns: " << linkedCharBag.getFrequencyOf('B') << std::endl;
	std::cout << "getFrequencyOf('X') returns: " << linkedCharBag.getFrequencyOf('X') << std::endl;

	std::cout << "contains('B') returns: " << linkedCharBag.contains('B') << std::endl;
	std::cout << "contains('X') returns: " << linkedCharBag.contains('X') << std::endl;

	std::cout << "remove('A') returns: " << linkedCharBag.remove('A') << std::endl;
	std::cout << "remove('X') returns: " << linkedCharBag.remove('X') << std::endl;

	std::cout << "displayContents() produces: " << std::endl;
	linkedCharBag.displayContents();

	std::cout << "copy LinkedBag with copy constructor: " << std::endl;
	LinkedBag<char> linkedCharBag2(linkedCharBag);
	linkedCharBag2.add('Z');
	linkedCharBag.displayContents();
	linkedCharBag2.displayContents();

	std::cout << "clear() produces: " << std::endl;
	linkedCharBag.clear();
	linkedCharBag.displayContents();

	return 0;
}
