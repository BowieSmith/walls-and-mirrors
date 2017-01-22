#include <iostream>

int totalsolveTowersCalls = 0;

void solveTowers(int count, char source, char destination, char spare)
{
  std::cout << "Enter solverTowers(). Count=" << count << " Source=" << source
            << " Destination=" << destination << " Spare=" << spare << std::endl;
  totalsolveTowersCalls += 1;
  if (count == 1)
  {
    std::cout << "Move top disk from pole " << source
              << " to pole " << destination << std::endl;
  }
  else
  {
    solveTowers(count - 1, source, spare, destination);
    solveTowers(1, source, destination, spare);
    solveTowers(count - 1, spare, destination, source);
  }
  std::cout << "Leave solverTowers(). Count=" << count << " Source=" << source
            << " Destination=" << destination << " Spare=" << spare << std::endl;
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
