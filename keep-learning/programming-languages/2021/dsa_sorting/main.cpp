// created by Nordin Suleimani on 2022-12-20
// Laboration 2 - DoA

#include <iostream>
#include <vector>

#include "DataGenerator.h"
#include "SortAlgorithmer.h"
#include "dataOutputer.h"

using namespace doa_laboration02;

int main() {
  // Set the minimum and maximum size, the step and number of samples
  enum OPTIONS {
    min_size = 1000000, max_size = 10000000, step = 1000000, num_samples = 5 // for not sorted data
//    min_size = 1000, max_size = 10000, step = 1000, num_samples = 5 // for sorted data
  };

  // Set the data set generation functions
  std::vector<std::vector<int> (*)(int)> data_funcs{makeConstVector, makeDescVector, makeAscVector, makeRandomVector};
  std::vector<std::string> data_names{"const", "desc", "asc", "rand"};

  // Set the sorting algorithms
  std::vector<void (*)(std::vector<int> &)> sort_funcs{stdSort};
  std::vector<std::string> sort_names{"std_sort"};

  // Loop through the data set generation functions
  for (int i = 0; i < data_funcs.size(); i++) {
    // Get the data set generation function and name
    auto data_func = data_funcs[i];
    auto data_name = data_names[i];

    // Loop through the sorting algorithms
    for (int j = 0; j < sort_funcs.size(); j++) {
      // Get the sorting algorithm and name
      auto sort_func = sort_funcs[j];
      auto sort_name = sort_names[j];

      // Perform the measurements for the current data set
      perform_measurements(sort_func, data_func, min_size, max_size, step, num_samples, sort_name, data_name);
    }
  }
  return 0;
}