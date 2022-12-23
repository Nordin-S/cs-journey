//
// Created by nordi on 12/8/2022.
//


#include "Car.h"
namespace metodik_laboration05 {
  Car::Car(std::string make, double horsepower)
      : m_make(make), m_horsepower(horsepower) {}

  std::string Car::getMake() const {
    return m_make;
  }

  double Car::getHorsepower() const {
    return m_horsepower;
  }

  bool Car::operator==(const Car &other) const {
    return m_make == other.m_make;
  }
}// namespace metodik_laboration05