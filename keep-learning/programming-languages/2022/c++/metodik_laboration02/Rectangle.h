//
// Created by nordi on 11/24/2022.
//

#ifndef METODIK_LABORATION02_RECTANGLE_H
#define METODIK_LABORATION02_RECTANGLE_H

#include "Shape.h"
namespace metodik_laboration02 {

class Rectangle : public Shape {
public:
  Rectangle() = delete;
  explicit Rectangle(std::string colour, double width, double height);
//  ~Rectangle();

  [[nodiscard]] double getWidth() const;
  void setWidth(double width);
  [[nodiscard]] double getHeight() const;
  void setHeight(double height);
  [[nodiscard]] double getArea() const override;

private:
  double m_width;
  double m_height;
};

} // namespace metodik_laboration02

#endif // METODIK_LABORATION02_RECTANGLE_H
