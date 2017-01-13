#include "LinkedBag.h"

void fillBag(LinkedBag<int>& bag, int start, int stop)
{
	bag.add(start);
	if (start < stop)
	{
		fillBag(bag, start + 1, stop);
	}
}

int main()
{
	LinkedBag<int> intBag;
	fillBag(intBag, 1, 1000);
	intBag.displayContents();

	int intArray[] = {2,4,6,8,10,12,14};
	LinkedBag<int> intBag2(intArray, 7);
	intBag2.displayContents();
}
