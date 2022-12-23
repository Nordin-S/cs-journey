//
// Created by nordi on 12/8/2022.
//

#include "MyPrint.h"

namespace metodik_laboration05 {
  void MyPrint::operator()(const Car &car) const {
    std::cout << "# Make: " << car.getMake() << ", Horsepower: " << car.getHorsepower() << "\n";
  }
}// namespace metodik_laboration05