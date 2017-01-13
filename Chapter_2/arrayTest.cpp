#include <iostream>

int binarySearch(const int anArray[], int first, int last, int target)
{
  int index = 0;
  if (first > last)
    index = -1;
  else
  {
    int mid = first + (last - first) / 2;
    if (target == anArray[mid])
      index = mid;
    else if (target < anArray[mid])
      index = binarySearch(anArray, first, mid - 1, target);
    else
      index = binarySearch(anArray, mid + 1, last, target);
  }
  return index;
}

int binaryMaxValue(const int anArray[], int startIndex, int endIndex)
{
  std::cout << "Enter binaryMaxValue with index values: " << startIndex << " "
            << endIndex << std::endl;
  if (endIndex - startIndex <= 1)
  {
    std::cout << "Leave binaryMaxValue with final value: " << anArray[startIndex] << std::endl;
    return anArray[startIndex];
  }
  else
  {
    int mid = startIndex + (endIndex - startIndex) / 2;

    std::cout << "Enter binaryMaxValue firstHalf with index values: "
              << startIndex << " " << mid << std::endl;
    int maxFirstHalf = binaryMaxValue(anArray, startIndex, mid);

    std::cout << "Enter binaryMaxValue secondHalf with index values: "
              << mid << " " << endIndex << std::endl;
    int maxSecondHalf = binaryMaxValue(anArray, mid, endIndex);

    std::cout << "Leave binaryMaxValue with index values: " << startIndex << " "
              << endIndex << std::endl;
    if (maxFirstHalf > maxSecondHalf)
      return maxFirstHalf;
    else
      return maxSecondHalf;
  }
}

void fillArray(int* intArray, int size, int step)
{
  for (int i = 0; i < size; i++)
    intArray[i] = i * step;
}

void printArray(int* intArray, int size)
{
  for (int i = 0; i < size; i++)
    std::cout << intArray[i] << " ";
}

int main()
{
  int intArray[100];
  fillArray(intArray, 100, 7);
  printArray(intArray, 100);

  std::cout << "The value 147 is found at position: "
            << binarySearch(intArray, 0, 99, 147) << std::endl;

  int ia[] = {7, 5, 13, 1, 4, 18, 9};
  std::cout << "\n\nMax Int: " << binaryMaxValue(ia, 0, 6) << std::endl;
}
