//
// Created by nordi on 11/24/2022.
//

#ifndef METODIK_LABORATION02_CYLINDER_H
#define METODIK_LABORATION02_CYLINDER_H

#include "Circle.h"
namespace metodik_laboration02 {

class Cylinder: public Circle {
public:
  Cylinder() = delete;
  explicit Cylinder(std::string colour, double radius, double height);
//  ~Cylinder();

  [[nodiscard]] double getHeight() const;
  void setHeight(double height);
  [[nodiscard]] double getArea() const override;

private:
  double m_height;
};

} // namespace metodik_laboration02

#endif // METODIK_LABORATION02_CYLINDER_H
