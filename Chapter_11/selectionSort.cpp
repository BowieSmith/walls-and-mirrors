#include <iostream>
#include <cstdlib>
#include <ctime>

template<class ItemType>
int findIndexOfLargest(const ItemType theArray[], int size)
{
	int largestIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (theArray[i] > theArray[largestIndex])
		{
			largestIndex = i;
		}
	}
	return largestIndex;
}

template<class ItemType>
void selectionSort(ItemType theArray[], int n)
{
	for (int last = n - 1; last >= 1; last--)
	{
		int largestIndex = findIndexOfLargest(theArray, last + 1);
		std::swap(theArray[largestIndex], theArray[last]);
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

	selectionSort(randomIntArray, ARRAY_SIZE);
	displayArray(randomIntArray, ARRAY_SIZE);
	std::cout << "\n\n";
}
