const double PI = 3.14159;

class Sphere
{
private:
  double theRadius;

public:
  Sphere();
  Sphere(double initialRadius);
  void setRadius(double newRadius);
  double getRadius() const;
  double getDiameter() const;
  double getCircumference() const;
  double getArea() const;
  double getVolume() const;
};
