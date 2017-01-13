#include <iostream>

int fib_iter_helper(int prevPrev, int prev, int count)
{
  if (count == 0)
    return prevPrev;
  else
    return fib_iter_helper(prev, prevPrev + prev, count - 1);
}

int fib_iter(int n)
{
  return fib_iter_helper(0, 1, n);
}


int main()
{
  int num;
  std::cout << "\nFibonacci number finder."
            << "\nEnter an integer to find the corresponding Fibonaaci number: ";
  std::cin >> num;
  std::cout << "\nFib number " << num << ": " << fib_iter(num) << "\n\n";
}
