//
// Created by nordi on 12/13/2022.
//

#include "MyFunc.h"

namespace metodik_laboration05 {
  MyFunc::MyFunc(double average): average(average) {
  }
  double MyFunc::operator()(const double &newValue) const {
    return newValue - average;
  }
}// namespace metodik_laboration05