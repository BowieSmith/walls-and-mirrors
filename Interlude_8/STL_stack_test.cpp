#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::stack<int> aStack;

	if (aStack.empty())
	{
		std::cout << "Stack is empty.\n";
	}

	for (int j = 0; j < 10; j++)
	{
		aStack.push(j);
	}

	while (!aStack.empty())
	{
		std::cout << "Size of stack: " << aStack.size() << "\n"
				  << "Top item: " << aStack.top() << "\n";
		aStack.pop();
	}

	return 0;
}
