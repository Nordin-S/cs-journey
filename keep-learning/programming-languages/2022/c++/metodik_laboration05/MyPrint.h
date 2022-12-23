//
// Created by nordi on 12/8/2022.
//

#ifndef METODIK_LABORATION05_MYPRINT_H
#define METODIK_LABORATION05_MYPRINT_H

#include "car.h"
#include <iostream>

namespace metodik_laboration05 {
  class MyPrint {
public:
    void operator()(const Car &car) const;
  };
}// namespace metodik_laboration05

#endif//METODIK_LABORATION05_MYPRINT_H
