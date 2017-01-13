#include <iostream>

long totalFibCalls = 0;

int fib(int n)
{
  totalFibCalls += 1;
  return ((n < 2) ? n : fib(n - 1) + fib(n - 2));
}

int main()
{
  std::cout << "\nFibonacci Finder.\n\n"
            << "Enter a positive integer: ";

  int input;
  std::cin >> input;

  std::cout << "\nFibonacci number " << input
            << " = " << fib(input) << '\n'
            << "Function calls: " << totalFibCalls << "\n\n";

  return 0;
}
