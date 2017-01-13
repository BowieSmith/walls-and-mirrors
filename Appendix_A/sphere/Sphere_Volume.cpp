#include <iostream>
int main()
{
  // Compute the volume of a sphere with the given radius
  const double PI = 3.14159;
  double radius;

  std::cout << "Enter the radius of the spehere: ";
  std::cin >> radius;

  double volume = 4 * PI * radius * radius * radius / 3;

  std::cout << "The volume of a sphere of radius "
            << radius << " inches is : " << volume
            << " cubic inches.\n";
  return 0;
}
