#include <iostream>

int totalsolveTowersCalls = 0;

void solveTowers(int count, char source, char desination, char spare)
{
  totalsolveTowersCalls += 1;
  if (count == 1)
  {
    std::cout << "Move top disk from pole " << source
              << " to pole " << desination << std::endl;
  }
  else
  {
    solveTowers(count - 1, source, spare, desination);
    solveTowers(1, source, desination, spare);
    solveTowers(count - 1, spare, desination, source);
  }
}

int main()
{
  int count;
  std::cout << "Enter the number of discs to start: ";
  std::cin >> count;
  solveTowers(count,'A','B','C');
  std::cout << "\nIt took " << totalsolveTowersCalls << " calls to the function"
            << " solveTowers() to solve the puzzel." << std::endl;
}
