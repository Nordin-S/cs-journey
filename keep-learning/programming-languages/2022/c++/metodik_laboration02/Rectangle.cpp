//
// Created by nordi on 11/24/2022.
//

#include "Rectangle.h"

namespace metodik_laboration02 {
Rectangle::Rectangle(std::string colour, double width = double(),
                     double height = double())
    : Shape(std::move(colour)), m_width(width), m_height(height) {
  setShapeType("Rectangle");
}
// Rectangle::~Rectangle() = default;

double Rectangle::getArea() const { return m_width * m_height; }
double Rectangle::getWidth() const { return m_width; }
void Rectangle::setWidth(double width) { m_width = width; }
double Rectangle::getHeight() const { return m_height; }
void Rectangle::setHeight(double height) { m_height = height; }
} // namespace metodik_laboration02