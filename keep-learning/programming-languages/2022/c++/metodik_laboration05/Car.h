//
// Created by nordi on 12/8/2022.
//

#ifndef METODIK_LABORATION05_CAR_H
#define METODIK_LABORATION05_CAR_H

#include <string>
namespace metodik_laboration05 {
  class Car {
public:
    Car(std::string make, double horsepower);

    std::string getMake() const;
    double getHorsepower() const;

    bool operator==(const Car &other) const;

private:
    std::string m_make;
    double m_horsepower;
  };

}// namespace metodik_laboration05

#endif//METODIK_LABORATION05_CAR_H
