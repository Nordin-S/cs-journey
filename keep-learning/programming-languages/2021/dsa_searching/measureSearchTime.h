//
// Created by nordin on 05/07/2023.
//

#ifndef DOA_LABORATION03_MEASURESEARCHTIME_H
#define DOA_LABORATION03_MEASURESEARCHTIME_H

#include <chrono>
namespace doa_laboration03 {
  // Define a search function type
  typedef std::function<int(const void*, int)> SearchFunction;

//  using searchFunction = std::function<int(const void*, int)>;


  // Measure search time for each search target for a specific search algorithm
  std::vector<double> measureSearchTime(SearchFunction searchFunction, const void* dataStructure, const std::vector<int>& searchTargets) {
    std::chrono::steady_clock::time_point begin, end;
    std::chrono::duration<double> targetTime;
    std::vector<double> searchTimes;

    for (int target : searchTargets) {
      begin = std::chrono::steady_clock::now();
      searchFunction(dataStructure, target);
      end = std::chrono::steady_clock::now();
      targetTime = std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
      searchTimes.push_back(targetTime.count());
    }

    return searchTimes;
  }} // doa_laboration03

#endif //DOA_LABORATION03_MEASURESEARCHTIME_H
