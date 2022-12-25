//
// Created by nordi on 12/23/2022.
//

#ifndef DOA_LABORATION02_MEASURESORTTIME_H
#define DOA_LABORATION02_MEASURESORTTIME_H

#include <chrono>
namespace doa_laboration02 {
  // Function to measure time for a sorting algorithm on a data set
  double measure_time(void (*sort_func)(std::vector<int> &), std::vector<int> &data) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    sort_func(data);
    auto end = high_resolution_clock::now();
    auto elapsed_time = duration_cast<milliseconds>(end - start).count();
    return static_cast<double>(elapsed_time);
  }
} // doa_laboration02

#endif //DOA_LABORATION02_MEASURESORTTIME_H
