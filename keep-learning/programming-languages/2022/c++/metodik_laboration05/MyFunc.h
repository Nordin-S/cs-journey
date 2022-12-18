//
// Created by nordi on 12/13/2022.
//

#ifndef METODIK_LABORATION05_MYFUNC_H
#define METODIK_LABORATION05_MYFUNC_H

namespace metodik_laboration05 {

  class MyFunc {
public:
    MyFunc() = default;
    explicit MyFunc(double average);

    double operator()(const double &newValue) const;
private:
    double average{};
  };

}// namespace metodik_laboration05

#endif//METODIK_LABORATION05_MYFUNC_H
