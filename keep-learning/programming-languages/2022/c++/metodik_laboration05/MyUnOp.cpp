//
// Created by nordi on 12/13/2022.
//

#include "MyUnOp.h"

namespace metodik_laboration05 {
  double MyUnOp::operator()(Car &car) {
    return car.getHorsepower();
  }
}// namespace metodik_laboration05