#include <iostream>
#include <cstdlib>

template<class ItemType>
void insertionSort(ItemType theArray[], int size)
{
	for (int unsorted = 1; unsorted < size; unsorted++)
	{
		ItemType nextItem = theArray[unsorted];
		int loc = unsorted;
		while ((loc > 0) && (theArray[loc - 1] > nextItem))
		{
			theArray[loc] = theArray[loc - 1];
			loc--;
		}
		theArray[loc] = nextItem;
	}
}

template<class ItemType>
void buildRandomArray(ItemType array[], int size, int range)
{
	std::srand(std::time(NULL));

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % range;
	}
}

template<class ItemType>
void displayArray(const ItemType itemArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << itemArray[i] << ", ";
	}
}

int main()
{
	const int ARRAY_SIZE = 50;
	int randomIntArray[ARRAY_SIZE];
	buildRandomArray(randomIntArray, ARRAY_SIZE, 100);

	displayArray(randomIntArray, ARRAY_SIZE);
	std::cout << "\n\n";

	insertionSort(randomIntArray, ARRAY_SIZE);
	displayArray(randomIntArray, ARRAY_SIZE);
	std::cout << "\n\n";
}
