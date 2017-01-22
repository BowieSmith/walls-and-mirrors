#include <iostream>
#include <string>
#include <regex>

bool isIdentifier(std::string input)
{
	std::regex identifier("[[:lower:]]");
	return std::regex_match(input,identifier);
}

bool isOperator(std::string input)
{
	std::regex operatr("(\\+|-|/|\\*)");
	return std::regex_match(input,operatr);
}

std::string charToString(char ch)
{
	std::string str(1, ch);
	return str;
}

int endPre(std::string strExp, int first)
{
	int last = strExp.size() - 1;
	if (first < 0 || first > last)
	{
		return -1;
	}

	std::string ch = charToString(strExp[first]);
	if (isIdentifier(ch))
	{
		return first;
	}
	else if (isOperator(ch))
	{
		int endPos = endPre(strExp, first + 1);
		if (endPos > -1)
		{
			return endPre(strExp, endPos + 1);
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
	return -1;
}

bool isPrefix(std::string strExp)
{
	int lastChar = endPre(strExp, 0);
	return (lastChar >= 0) && (lastChar == strExp.size() - 1);	
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "ERROR: Form -> 'isPrefix <string>'" << std::endl;
		return 0;
	}
	
	std::string exp(argv[1]);

	if (isPrefix(exp))
		std::cout << "'" << exp << "'" << " is a valid prefix expression!" << std::endl;
	else
		std::cout << "'" << exp << "'" << " is NOT a valid prefix expression." << std::endl;

	return 0;
}
