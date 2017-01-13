#include <iostream>

long fact(int n, long product)
{
  if (n < 0)
  {
    return 0;
  }
  else if (n == 0)
  {
    return product;
  }
  else
  {
    return fact(n - 1, product * n);
  }
}

int main()
{
  std::cout << "\nEnter an integer: ";
  int n;
  std::cin >> n;

  std::cout << "Factorial of " << n << ": " << fact(n,1) << std::endl;

  return 0;
}
