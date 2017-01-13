#include <iostream>
#include "SphereInColor.h"

int main()
{
  double rad;
  int numColor;

  std::cout << "\n\nEnter a radius: ";
  std::cin >> rad;
  std::cout << "\nEnter a color (0,1,2,3): ";
  std::cin >> numColor;

  Color myColor = static_cast<Color>(numColor);

  SphereInColor ball(myColor, rad);

  std::cout << "\nColor of ball: " << ball.getColor()
            << "\nRadius of ball: " << ball.getRadius()
            << "\nArea of ball: " << ball.getArea()
            << "\nVolume of ball: " << ball.getVolume()
            << "\n\n";

  return 0;
}
