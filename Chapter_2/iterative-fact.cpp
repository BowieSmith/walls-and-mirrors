#include <iostream>

long fact(long n)
{
  if (n < 0)
  {
    return 0;
  }
  else
  {
    long product = 1;
    for (int i = 1; i <= n; i++)
    {
      product *= i;
    }
    return product;
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
