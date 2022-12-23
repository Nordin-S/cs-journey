//
// Created by nordi on 11/24/2022.
//

#ifndef METODIK_LABORATION02_PARALLELEPIPED_H
#define METODIK_LABORATION02_PARALLELEPIPED_H

#include "Rectangle.h"
namespace metodik_laboration02 {

class Parallelepiped : public Rectangle {
public:
  Parallelepiped() = delete;
  explicit Parallelepiped(std::string colour, double width, double height,
                          double length);
//  ~Parallelepiped();

  [[nodiscard]] double getLength() const;
  void setLength(double length);
  [[nodiscard]] double getArea() const override;

private:
  double m_length;
};
} // namespace metodik_laboration02

#endif // METODIK_LABORATION02_PARALLELEPIPED_H
