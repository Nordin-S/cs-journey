// DataGenerator.hpp

#ifndef DATAGENERATOR_HPP
#define DATAGENERATOR_HPP

#include <vector>
#include <algorithm>

#include <ctime>
#include <algorithm>
#include "DataGenerator.h"

namespace doa_laboration02 {
  std::vector<int> makeRandomVector(int size) {
    std::vector<int> buffer(size);
    std::srand(std::time(nullptr));
    std::generate(buffer.begin(), buffer.end(),
                  [size]() { return rand() % size; });
    return buffer;
  }

  std::vector<int> makeAscVector(int size) {
    std::vector<int> buffer(size);
    int i = 0;
    std::generate(buffer.begin(), buffer.end(),
                  [&]() { return i++; });
    return buffer;
  }

  std::vector<int> makeDescVector(int size) {
    std::vector<int> buffer(size);
    int i = size;
    std::generate(buffer.begin(), buffer.end(),
                  [&]() { return i--; });
    return buffer;
  }

  std::vector<int> makeConstVector(int size) {
    const int VALUE = rand() % size;
    std::vector<int> buffer(size, VALUE);
    return buffer;
  }
} // doa_laboration02
#endif// doa_laboration02
