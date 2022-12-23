//
// Created by nordi on 11/24/2022.
//

#ifndef METODIK_LABORATION02_CIRCLE_H
#define METODIK_LABORATION02_CIRCLE_H

#include "Shape.h"
namespace metodik_laboration02 {

class Circle : public Shape {
public:
  Circle() = delete;
  explicit Circle(std::string colour, double radius);
//  ~Circle();

  [[nodiscard]] double getRadius() const;
  void setRadius(double radius);
  [[nodiscard]] double getArea() const override;

private:
  double m_radius;
};

} // namespace metodik_laboration02

#endif // METODIK_LABORATION02_CIRCLE_H
