#include <iostream>
#include <string>
#include "ArrayBag.h"

using std::cout;
using std::endl;

void displayBag(ArrayBag<std::string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize() << " items:" << endl;
	std::vector<std::string> bagItems = bag.toVector();

	int numberOfEntries = (int)bagItems.size();
	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}
	cout << endl << endl;
}

void bagTester(ArrayBag<std::string>& bag)
{
	cout << "isEmpty: returns " << bag.isEmpty() << "; should be 1 (true)" << endl;
	displayBag(bag);

	std::string items[] = { "one", "two", "three", "five", "one" };
	cout << "Add 5 items to the bag: " << endl;
	for (int i = 0; i < 5; i++)
	{
		bag.add(items[i]);
	}

	displayBag(bag);
	cout << "isEmpty: returns " << bag.isEmpty() << "; should be 0 (false)" << endl;
	cout << "getCurrentSize: returns " << bag.getCurrentSize() << "; should be 5" << endl;
	cout << "Try to add another entry: add(\"extra\") returns " << bag.add("extra") << endl;

	cout << "contains(\"extra\"): returns " << bag.contains("extra") << endl;
	cout << "contains(\"fifty\"): returns " << bag.contains("fifty") << endl;
	
	cout << "getFrequencyOf(\"one\"): returns " << bag.getFrequencyOf("one") << endl;
	cout << "getFrequencyOf(\"two\"): returns " << bag.getFrequencyOf("two") << endl;
	cout << "getFrequencyOf(\"fifty\"): returns " << bag.getFrequencyOf("fifty") << endl;
	displayBag(bag);

	cout << "remove(\"five\"): returns " << bag.remove("five") << endl;
	displayBag(bag);

	cout << "clear(): returns void" << endl;
	bag.clear();
	displayBag(bag);
}

int main()
{
	ArrayBag<std::string> bag;
	cout << "Testing the Array-Based Bag:" << endl;
	cout << "The initial bag is empty." << endl;
	bagTester(bag);
	cout << "All done!" << endl;

	return 0;
}
