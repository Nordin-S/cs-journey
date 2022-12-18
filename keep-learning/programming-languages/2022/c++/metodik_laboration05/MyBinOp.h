//
// Created by nordi on 12/8/2022.
//

#ifndef METODIK_LABORATION05_MYBINOP_H
#define METODIK_LABORATION05_MYBINOP_H

#include "Car.h"
#include <functional>

namespace metodik_laboration05 {

  template<typename T>
  class MyBinOp {

private:
    double total;
    size_t count;

public:
    MyBinOp() = default;

    explicit MyBinOp(size_t count);

    void operator()(double total);

    double average() const;
  };

  template<typename T>
  double MyBinOp<T>::average() const {
    return total / count;
  }

  template<typename T>
  void MyBinOp<T>::operator()(double newTotal) {
    total = newTotal;
  }

  template<typename T>
  MyBinOp<T>::MyBinOp(size_t count) : count(count) {}

}// namespace metodik_laboration05

#endif//METODIK_LABORATION05_MYBINOP_H
