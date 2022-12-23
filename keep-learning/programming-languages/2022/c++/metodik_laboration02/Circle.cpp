//
// Created by nordi on 11/24/2022.
//

#include "Circle.h"
#include <cmath>

namespace metodik_laboration02 {
Circle::Circle(std::string colour, double radius = double())
    : Shape(colour), m_radius(radius) {
  setShapeType("Circle");
}
//Circle::~Circle() = default;

double Circle::getRadius() const { return m_radius; }
void Circle::setRadius(double radius) { m_radius = radius; }
double Circle::getArea() const { return M_PI * pow(m_radius, 2); }
} // namespace metodik_laboration02