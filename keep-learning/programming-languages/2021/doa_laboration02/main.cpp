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
    min_size = 1000, max_size = 10000, step = 1000, num_samples = 5
  }; // for not sorted data
//  enum OPTIONS{min_size = 20000, max_size = 200000, step = 20000, num_samples = 5}; // for sorted data

  // Set the data set generation functions
  std::vector<std::vector<int> (*)(int)> data_funcs{makeDescVector, makeRandomVector};
  std::vector<std::string> data_names{"DescendingData", "RandomData"};

  // Set the sorting algorithms
  std::vector<void (*)(std::vector<int> &)> sort_funcs{insertion_sort, selection_sort, quick_sort_right_pivot,
                                                       quick_sort_mot_pivot};
  std::vector<std::string> sort_names{"insertion_sort", "selection_sort", "quick_sort_right_pivot",
                                      "quick_sort_mot_pivot"};

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

//  // int vector with 10 random elements
//  std::vector<int> data = makeRandomVector(10);
//  // int vector with 10 ascending elements
//  std::vector<int> data2 = makeAscVector(10);
//  // int vector with 10 descending elements
//  std::vector<int> data4 = makeAscVector(10);
//  //   int vector with 10 constant elements
//  std::vector<int> data4 = makeConstVector(10000000);
//
//  // sort data with insertion sort
//  insertion_sort(data);
//  // sort data2 with insertion sort
//  insertion_sort(data2);
//  // sort data3 with insertion sort
//  insertion_sort(data3);
//  // sort data4 with insertion sort
//  insertion_sort(data4);


//  std::cout << measure_time(insertion_sort, data4) << std::endl;

  return 0;
}