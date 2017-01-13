#include "Sphere.h"

enum Color {RED, BLUE, GREEN, YELLOW};

class SphereInColor : public Sphere
{
private:
  Color sphereColor;

public:
  SphereInColor(Color initialColor);
  SphereInColor(Color initialColor, double initialRadius);
  void setColor(Color newColor);
  Color getColor() const;
};
