#include <iostream>
#include <cmath>

int main()
{
  int n;
  long sum_squares = 0;

  std::cout << "\nThis program finds the sum of the first n squares.\n"
            << "Enter a value for n: ";
  std::cin >> n;

  for (int i = 0; i <= n; i++)
    sum_squares += std::pow(i,2);

  std::cout << "Sum of first " << n << " squares equals: "
            << sum_squares << "\n\n";

  return 0;
}
