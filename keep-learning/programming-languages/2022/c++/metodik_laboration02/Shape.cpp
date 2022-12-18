//
// Created by nordi on 11/24/2022.
//

#include "Shape.h"

namespace metodik_laboration02 {

Shape::Shape(std::string colour) : m_colour(std::move(colour)) {}
const std::string &Shape::getColour() const { return m_colour; }
void Shape::setColour(std::string colour) { m_colour = std::move(colour); }
const std::string &Shape::getShapeType() const { return m_shapeType; }
void Shape::setShapeType(std::string shapeType) { m_shapeType = shapeType; }
} // namespace metodik_laboration02