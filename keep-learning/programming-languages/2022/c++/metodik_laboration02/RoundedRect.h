//
// Created by nordi on 11/24/2022.
//

#ifndef METODIK_LABORATION02_ROUNDEDRECT_H
#define METODIK_LABORATION02_ROUNDEDRECT_H

#include "Rectangle.h"
namespace metodik_laboration02 {

class RoundedRect : public Rectangle {
public:
  RoundedRect() = delete;
  explicit RoundedRect(std::string colour, double width, double height,
                       double cornerRadius);
//  ~RoundedRect();

  [[nodiscard]] double getCornerRadius() const;
  void setCornerRadius(double cornerRadius);
  [[nodiscard]] double getArea() const override;
private:
  double m_cornerRadius;
};

} // namespace metodik_laboration02

#endif // METODIK_LABORATION02_ROUNDEDRECT_H
