//
// Created by nordi on 12/25/2022.
//

#ifndef DOA_LABORATION02_DATAOUTPUTER_H
#define DOA_LABORATION02_DATAOUTPUTER_H

#include <fstream>
#include <numeric>
#include <cmath>
#include <iostream>

#include "SortAlgorithmer.h"
#include "DataGenerator.h"
#include "measureSortTime.h"

namespace doa_laboration02 {
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

      // Calculate the standard deviation
      double sq_sum = std::inner_product(times.begin(), times.end(), times.begin(), 0.0);
      double stddev = std::sqrt(sq_sum * (1.0 / (size - 1)));
      // Write the results to the output file
      out_file << size << "," << mean << "," << stddev << "," << num_samples << "\n";
    }

    // Close the output file
    out_file.close();
  }

} // doa_laboration02

#endif //DOA_LABORATION02_DATAOUTPUTER_H
