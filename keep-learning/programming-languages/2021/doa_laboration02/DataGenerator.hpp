// DataGenerator.hpp

#ifndef DATAGENERATOR_HPP
#define DATAGENERATOR_HPP

#include <cstddef>
#include <string>
#include <vector>

// a class that generates dataset for vector based on given size, 
// and returns the vector as a result, random data, ascending data, descending data
class DataGenerator {
public:
    // constructor
    DataGenerator();
    // destructor
    ~DataGenerator();
    // generates a vector with random data
    std::vector<int> randomVector(size_t size);
    // generates a vector with ascending data
    std::vector<int> ascVector(size_t size);
    // generates a vector with descending data
    std::vector<int> descVector(size_t size);
    // generates a vector with constant data
    std::vector<int> constVector(size_t size);
};

#endif
