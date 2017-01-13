#include <iostream>

long fact(long n)
{
  if (n < 0)
  {
    return 0;
  }
  else if (n == 0)
  {
    return 1;
  }
  else
  {
    return n * fact(n - 1);
  }
}

int main()
{
  std::cout << "\nEnter an integer: ";
  int n;
  std::cin >> n;

  std::cout << "Factorial of " << n << ": " << fact(n) << std::endl;

  return 0;
}
