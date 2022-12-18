//
// Created by nordi on 11/24/2022.
//

#include "Parallelepiped.h"

namespace metodik_laboration02 {
Parallelepiped::Parallelepiped(std::string colour, double width = double(),
                               double height = double(),
                               double length = double())
    : Rectangle(std::move(colour), width, height), m_length(length) {
  setShapeType("Parallelepiped");
}
//Parallelepiped::~Parallelepiped() = default;

double Parallelepiped::getLength() const { return m_length; }
void Parallelepiped::setLength(double length) { m_length = length; }
double Parallelepiped::getArea() const {
  return Rectangle::getArea() * 2 + 2 * getHeight() * m_length +
         2 * getWidth() * m_length;
}
} // namespace metodik_laboration02