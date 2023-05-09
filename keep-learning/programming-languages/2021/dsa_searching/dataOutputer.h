//
// Created by nordin on 05/07/2023.
//

#ifndef DOA_LABORATION03_DATAOUTPUTER_H
#define DOA_LABORATION03_DATAOUTPUTER_H

#include <fstream>
#include <numeric>
#include <cmath>
#include <iostream>
#include <utility>
#include <valarray>

#include "SearchAlgorithmer.h"
#include "DataGenerator.h"
#include "measureSearchTime.h"

namespace doa_laboration03 {

  double std_dev(std::vector<double> searchTimesVector) {
    std::valarray<double> searchTimesArray(searchTimesVector.data(), searchTimesVector.size());
    double sum = std::accumulate(std::begin(searchTimesArray), std::end(searchTimesArray), double());
    auto n = searchTimesArray.size();
    auto avg = sum / searchTimesArray.size();
    std::valarray<double> dev_squared = std::pow(searchTimesArray - avg, 2);
    double square_sum = std::accumulate(std::begin(dev_squared), std::end(dev_squared), double());
    return std::sqrt(square_sum * (1.0 / (n - 1)));
  }

// Function output measurement results to a file
  void dataOutputer(std::vector<double> searchTimesVector, size_t dataSize, size_t sampleSize, std::string searchName) {
    // Check if the file exists
    bool exists = std::ifstream(searchName + ".csv").good();

    // Check if the file is empty, and write the header if needed
    if (!exists) {
      std::ofstream out_file(searchName + ".csv");
      out_file << "#size,time_mean,std_dev,sample_size" << "\n";
      out_file.close();
    }
    // Open the output file in append mode
    std::ofstream out_file(searchName + ".csv", std::ios_base::app);

//    // Calculate the mean time
//    double mean = std::accumulate(searchTimesVector.begin(), searchTimesVector.end(), 0.0) / searchTimesVector.size();
//
//    // Calculate the standard deviation
//    double sq_sum = std::inner_product(searchTimesVector.begin(), searchTimesVector.end(), searchTimesVector.begin(),
//                                       0.0);
//    double mean_sq_sum = sq_sum / searchTimesVector.size();
//    double stddev = std::sqrt(mean_sq_sum - mean * mean);

      double mean = std::accumulate(searchTimesVector.begin(), searchTimesVector.end(), 0.0) / searchTimesVector.size();
      double stddev = std_dev(std::move(searchTimesVector));






    // Write the results to the output file
    out_file << dataSize << "," << mean << "," << stddev << "," << sampleSize << "\n";

    // Close the output file
    out_file.close();
  }
} // doa_laboration03

#endif //DOA_LABORATION03_DATAOUTPUTER_H
