//
// Created by nordi on 11/24/2022.
//

#ifndef METODIK_LABORATION02_SHAPE_H
#define METODIK_LABORATION02_SHAPE_H

#include <string>
namespace metodik_laboration02 {

class Shape {
public:
  Shape() = delete;
  explicit Shape(std::string colour);
  virtual ~Shape() = default;

  [[nodiscard]] const std::string &getColour() const;
  void setColour(std::string colour);
  [[nodiscard]] virtual double getArea() const = 0;
  [[nodiscard]] const std::string &getShapeType() const;
  void setShapeType(std::string shapeType);

private:
  std::string m_colour;
  std::string m_shapeType;
};

} // namespace metodik_laboration02

#endif // METODIK_LABORATION02_SHAPE_H
