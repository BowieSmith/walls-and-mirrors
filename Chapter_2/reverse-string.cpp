#include <iostream>
#include <string>

std::string reverseStringLoop(std::string input)
{
  std::string output = "";
  for (int i = input.size() - 1; i >= 0; i--)
  {
    output.append(input.substr(i, 1));
  }
  return output;
}

std::string reverseStringHelper(std::string input, std::string output)
{
  if (input.size() == 0)
    return output;
  else
  {
    std::string newOutput = output;
    newOutput.append(input.substr(input.size() - 1, 1));
    return reverseStringHelper(input.substr(0, input.size() - 1), newOutput);
  }
}

std::string reverseStringRecur(std::string input)
{
  return reverseStringHelper(input, "");
}

int main()
{
  std::cout << "\n" << reverseStringRecur("This is the end");
}
