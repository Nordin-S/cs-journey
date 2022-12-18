//
// Created by nordi on 11/24/2022.
//

#include "RoundedRect.h"
#include "Circle.h"
#include <cmath>

namespace metodik_laboration02 {
RoundedRect::RoundedRect(std::string colour, double width, double height,
                         double cornerRadius)
    : Rectangle(colour, width, height), m_cornerRadius(cornerRadius) {
  setShapeType("Rounded rectangle");
}
double RoundedRect::getCornerRadius() const { return m_cornerRadius; }
void RoundedRect::setCornerRadius(double cornerRadius) {
  m_cornerRadius = cornerRadius;
}
double RoundedRect::getArea() const {
//  double circleArea = M_PI * pow(m_cornerRadius, 2);
  double circleArea = (new Circle("blank", m_cornerRadius))->getArea();
  double squareArea = pow(2 * m_cornerRadius, 2);
  double roundCornerArea = squareArea - circleArea;
  return Rectangle::getArea() - roundCornerArea;
}
//RoundedRect::~RoundedRect() = default;
} // namespace metodik_laboration02