#include <iostream>
#include "Sphere.h"

int main()
{
  double rad;
  std::cout << "\nSphere stats.\nEnter a radius: ";
  std::cin >> rad;

  Sphere mySphere(rad);
  std::cout << "\nRadius is:        " << mySphere.getRadius()
            << "\nDiameter is:      " << mySphere.getDiameter()
            << "\nCircumference is: " << mySphere.getCircumference()
            << "\nArea is:          " << mySphere.getArea()
            << "\nVolume is:        " << mySphere.getVolume() << "\n\n";
  return 0;
}
