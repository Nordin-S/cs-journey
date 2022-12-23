//
// Created by nordi on 11/24/2022.
//

#include "Cylinder.h"
#include <cmath>

namespace metodik_laboration02 {
Cylinder::Cylinder(std::string colour, double radius = double(),
                   double height = double())
    : Circle(colour, radius), m_height(height) {
  setShapeType("Cylinder");
}
//Cylinder::~Cylinder() = default;

double Cylinder::getHeight() const { return m_height; }
void Cylinder::setHeight(double height) { m_height = height; }
double Cylinder::getArea() const {
  double cylinderSidesArea = Circle::getArea() * 2;
  double cylinderMantelArea = 2 * M_PI * getRadius() * m_height;
  return cylinderMantelArea + cylinderSidesArea;
}
} // namespace metodik_laboration02