// created by Nordin Suleimani on 2022-12-20
// Laboration 2 - DoA

#include <iostream>

#include "./DataGenerator.hpp"

int main() {
  DataGenerator dataGenerator;
  const size_t SMALL = 20;
  // const size_t MEDIUM = 40000;
  // const size_t LARGE = 60000;
  // const size_t HUGE = 80000;
  // const size_t ENORMOUS = 100000;
  // const size_t GIGANTIC = 200000;

  std::vector<int> randToSort_v = dataGenerator.randomVector(SMALL);
  std::vector<int> ascToSort_v = dataGenerator.ascVector(SMALL);
  std::vector<int> descToSort_v = dataGenerator.descVector(SMALL);
  std::vector<int> constToSort_v = dataGenerator.constVector(SMALL);

  // loop through vector and print out all values
  for (size_t i = 0; i < SMALL; i++) {
    std::cout << randToSort_v[i] << " " << ascToSort_v[i] << " "
              << descToSort_v[i] << " " << constToSort_v[i] << "\n";
  }
}
// !gcc % -o -g %< && ./%< && rm %
