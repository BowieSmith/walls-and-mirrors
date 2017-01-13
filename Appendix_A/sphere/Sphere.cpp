#include "Sphere.h"

Sphere::Sphere()
{
  theRadius = 1.0;
}

Sphere::Sphere(double initialRadius)
{
  setRadius(initialRadius);
}

void Sphere::setRadius(double newRadius)
{
  if (newRadius > 0)
    theRadius = newRadius;
  else
    theRadius = 1.0;
}

double Sphere::getRadius() const
{
  return theRadius;
}

double Sphere::getDiameter() const
{
  return theRadius * 2.0;
}

double Sphere::getCircumference() const
{
  return PI * getDiameter();
}

double Sphere::getArea() const
{
  return 4.0 * PI * theRadius * theRadius;
}

double Sphere::getVolume() const
{
  double radiusCubed = theRadius * theRadius * theRadius;
  return 4.0 * radiusCubed * PI / 3.0;
}
