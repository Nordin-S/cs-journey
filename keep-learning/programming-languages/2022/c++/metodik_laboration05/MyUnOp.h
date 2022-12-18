//
// Created by nordi on 12/13/2022.
//

#ifndef METODIK_LABORATION05_MYUNOP_H
#define METODIK_LABORATION05_MYUNOP_H

#include "Car.h"
namespace metodik_laboration05 {

  class MyUnOp {
public:
    MyUnOp() = default;

    double operator()(Car &car);
  };

}// namespace metodik_laboration05

#endif//METODIK_LABORATION05_MYUNOP_H
