#include <iostream>
#include "ToyBox.h"
#include "MagicBox.h"
#include <string>

int main()
{
	PlainBox<double> numberBox(7);
	PlainBox<std::string> nameBox("Bob");

	ToyBox<double> toyNumberBox(3.7, YELLOW);
	ToyBox<std::string> toyNameBox("Bruce", GREEN);

	MagicBox<double> magicNumberBox(7.3);
	MagicBox<std::string> magicNameBox("Bowie");

	std::cout << numberBox.getItem() << "\n"
			  		<< nameBox.getItem() << "\n" << std::endl;

	std::cout << toyNumberBox.getItem() << "\n"
						<< toyNumberBox.getColor() << "\n"
						<< toyNameBox.getItem() << "\n"
						<< toyNameBox.getColor() << "\n" << std::endl;

	std::cout << magicNumberBox.getItem() << "\n"
						<< magicNameBox.getItem() << "\n" << std::endl;

	magicNumberBox.setItem(99);
	magicNameBox.setItem("NoWay");

	std::cout << magicNumberBox.getItem() << "\n"
						<< magicNameBox.getItem() << "\n" << std::endl;

	return 0;
}
