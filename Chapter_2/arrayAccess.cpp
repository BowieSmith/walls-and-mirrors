#include <iostream>

int main()
{
	double values[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	std::cout << values[0] << values[2] << values[15] << std::endl;
	std::cout << &values << std::endl;

	int a = 3;
	int b = a / 2;
	std::cout << b;
}
