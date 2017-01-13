#include <iostream>

void countDown(int n)
{
	std::cout << n << std::endl;
	if (n > 0)
		countDown(n - 1);
}

int main()
{
	int i;
	std::cout << "\nEnter an integer value to count down from: ";
	std::cin >> i;

	countDown(i);
}
