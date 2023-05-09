//
// Created by nordi on 12/25/2022.
//

#ifndef DOA_LABORATION02_DATAOUTPUTER_H
#define DOA_LABORATION02_DATAOUTPUTER_H

#include <fstream>
#include <numeric>
#include <cmath>
#include <iostream>
#include <valarray>

#include "SortAlgorithmer.h"
#include "DataGenerator.h"
#include "measureSortTime.h"

namespace doa_laboration02 {
  double std_dev(std::vector<double> searchTimesVector) {
    std::valarray<double> searchTimesArray(searchTimesVector.data(), searchTimesVector.size());
    double sum = std::accumulate(std::begin(searchTimesArray), std::end(searchTimesArray), double());
    auto n = searchTimesArray.size();
    auto avg = sum / searchTimesArray.size();
    std::valarray<double> dev_squared = std::pow(searchTimesArray - avg, 2);
    double square_sum = std::accumulate(std::begin(dev_squared), std::end(dev_squared), double());
    return std::sqrt(square_sum * (1.0 / (n - 1)));
  }

// Function to perform the measurements for a single data set and output the results to a file
  void perform_measurements(void (*sort_func)(std::vector<int> &), std::vector<int> (*data_func)(int), int min_size,
                            int max_size, int step, int num_samples, std::string sort_name, std::string data_name) {
    // Open the output file
    std::ofstream out_file(sort_name + "_" + data_name + ".csv");

    // Write the header to the output file
    out_file << "#size,time,std_dev,sample_size" << "\n";

    // Loop through the sizes
    for (int size = min_size; size <= max_size; size += step) {
      // Vector to store the times for each sample
      std::vector<double> times;

      // Loop through the samples
      for (int k = 0; k < num_samples; k++) {
        // Generate the data
        std::vector<int> data = data_func(size);

        // Measure the time for the sorting algorithm
        double time = measure_time(sort_func, data);

        // Add the time to the vector
        times.push_back(time);
      }

      // Calculate the mean time
      double mean = std::accumulate(times.begin(), times.end(), 0.0) / times.size();

//      // Calculate the standard deviation
      double stddev = std_dev(std::move(times));

      // Write the results to the output file
      out_file << size << "," << mean << "," << stddev << "," << num_samples << "\n";
    }

    // Close the output file
    out_file.close();
  }

} // doa_laboration02

#endif //DOA_LABORATION02_DATAOUTPUTER_H
