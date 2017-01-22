#include <iostream>
#include <string>

bool assessPalindrome(std::string str);

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "ERROR: Must be of form 'palindrome <string>'" << std::endl;
		return 0;
	}

	std::string str(argv[1]);
	bool isPalindrome = assessPalindrome(str);
	if (isPalindrome)
		std::cout << "'" << str << "'" << " is a palindrome!" << std::endl;
	else
		std::cout << "'" << str << "'" << " is not a palindrome." << std::endl;

	return 0;
}

bool assessPalindrome(std::string str)
{
	if (str.size() < 2)
		return true;
	else if (str.front() == str.back())
		return assessPalindrome(str.substr(1, str.size() - 2));
	else
		return false;
}
