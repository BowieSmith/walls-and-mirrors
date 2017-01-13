#include <iostream>
#include <string>

void writeBackward(std::string str)
{
	std::cout << "Enter writeBackward with string: " << str << std::endl;
	if (str.size() > 0)
	{
		writeBackward(str.substr(1, str.size() - 1));
		std::cout << "About to write first character of string: " << str << std::endl;
		std::cout << str.substr(0,1);
	}
	std::cout << "Leave writeBackward with string: " << str << std::endl;
}

void writeBackward2(std::string str)
{
	std::cout << "Enter writeBackward2 with string: " << str << std::endl;
	if (str.size() > 0)
	{
		std::cout << "About to write last character of string: " << str << std::endl;
		std::cout << str.substr(str.size() - 1, 1);
		writeBackward2(str.substr(0, str.size() - 1));
	}
	std::cout << "Leave writeBackward2 with string: " << str << std::endl;
}

int main()
{
	writeBackward("cat");
	writeBackward2("cat");
}
