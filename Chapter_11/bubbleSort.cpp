#include <iostream>
#include <cstdlib>

template<class ItemType>
void bubbleSort(ItemType array[], int size)
{
	bool sorted = false;
	int pass = 1;
	while (!sorted && (pass < size))
	{
		sorted = true;
		for (int i = 0; i < size - pass; i++)
		{
			int nextIndex = i + 1;
			if (array[i] > array[nextIndex])
			{
				std::swap(array[i], array[nextIndex]);
				sorted = false;
			}
		}
		pass++;
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
	const int ARRAY_SIZE = 25000;
	int randomIntArray[ARRAY_SIZE];
	buildRandomArray(randomIntArray, ARRAY_SIZE, 100);

	displayArray(randomIntArray, ARRAY_SIZE);
	std::cout << "\n\n";

	bubbleSort(randomIntArray, ARRAY_SIZE);
	displayArray(randomIntArray, ARRAY_SIZE);
	std::cout << "\n\n";
}
