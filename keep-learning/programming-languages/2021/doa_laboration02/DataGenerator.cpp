// DataGenerator.cpp

#include "./DataGenerator.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

DataGenerator::DataGenerator() {
  // constructor
}

DataGenerator::~DataGenerator() {
  // destructor
}

std::vector<int> DataGenerator::randomVector(size_t size) {
  std::vector<int> randomVector(size);
  // generate random data with std::generate
  std::srand(std::time(nullptr));
  // generate random numbers between 0 and 100
  std::generate(randomVector.begin(), randomVector.end(),
                [size]() { return std::rand() % size; });
  return randomVector;
}

std::vector<int> DataGenerator::ascVector(size_t size) {
  std::vector<int> ascendingVector(size);
  static int i = 0;
  std::generate(ascendingVector.begin(), ascendingVector.end(),
                []() { return i++; });
  return ascendingVector;
}

std::vector<int> DataGenerator::descVector(size_t size) {
  std::vector<int> descendingVector(size);
  static int i = size;
  std::generate(descendingVector.begin(), descendingVector.end(),
                []() { return i--; });
  return descendingVector;
}

std::vector<int> DataGenerator::constVector(size_t size) {
  std::vector<int> constantVector(size);
  // fill vector with constant value using std::fill
  std::fill(constantVector.begin(), constantVector.end(), 5);
  return constantVector;
}
