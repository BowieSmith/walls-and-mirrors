#include "SphereInColor.h"

SphereInColor::SphereInColor(Color initialColor)
                             : Sphere()
{
  sphereColor = initialColor;
}

SphereInColor::SphereInColor(Color initialColor,
                             double initialRadius)
                             : Sphere(initialRadius)
{
  sphereColor = initialColor;
}

void SphereInColor::setColor(Color newColor)
{
  sphereColor = newColor;
}

Color SphereInColor::getColor() const
{
  return sphereColor;
}
