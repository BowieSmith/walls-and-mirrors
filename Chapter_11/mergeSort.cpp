#include <iostream>
#include <cstdlib>

template<class ItemType>
void merge(ItemType theArray[], int first, int mid, int last)
{
	ItemType tempArray[last];

	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (theArray[first1] <= theArray[first2])
		{
			tempArray[index] = theArray[first1];
			first1++;
		}
		else
		{
			tempArray[index] = theArray[first2];
			first2++;
		}
		index++;
	}

	while (first1 <= last1)
	{
		tempArray[index] = theArray[first1];
		first1++;
		index++;
	}

	while (first2 <= last2)
	{
		tempArray[index] = theArray[first2];
		first2++;
		index++;
	}

	for (index = first; index <= last; index++)
	{
		theArray[index] = tempArray[index];
	}
}

template<class ItemType>
void mergeSort(ItemType theArray[], int first, int last)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;
		mergeSort(theArray, first, mid);
		mergeSort(theArray, mid + 1, last);
		merge(theArray, first, mid, last);
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

	mergeSort(randomIntArray, 0, ARRAY_SIZE);
	displayArray(randomIntArray, ARRAY_SIZE);
	std::cout << "\n\n";
}
