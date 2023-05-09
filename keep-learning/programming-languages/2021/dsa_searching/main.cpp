//
// Created by nordin on 05/07/2023.
// Laboration 3 - DoA

#include <vector>
#include "DataGenerator.h"
#include "SearchAlgorithmer.h"
#include "dataOutputer.h"
#include <iostream>

using namespace doa_laboration03;

int main() {
  int lowerLimit = 100000;
  int upperLimit = 1000000;
  int stepSize = 100000;
  int numSearches = 500;

  for (int limit = lowerLimit; limit <= upperLimit; limit += stepSize) {
    std::vector<int>* primes = generatePrimeSeries(limit);
    Node* binaryTree = createBalancedBinaryTree(*primes);
    std::vector<HashNode*> hashTable = hashTableFromPrimes(*primes);

    int minValue = primes->front();
    int maxValue = primes->back();
    std::vector<int> randomSeries = generateRandomSeries(numSearches, minValue, maxValue);

//    std::vector<double> sequentialSearchTimes = measureSearchTime(
//      [](const void* arr, int target) -> int {
//        return sequentialSearch(*static_cast<const std::vector<int>*>(arr), target);
//      },
//      primes,
//      randomSeries
//    );
//    dataOutputer(sequentialSearchTimes, primes->size(), numSearches, "sequentialSearchTimes");

//    std::vector<double> binarySearchTime = measureSearchTime(
//      [](const void* arr, int target) -> int {
//        return binarySearch(*static_cast<const std::vector<int>*>(arr), target);
//      },
//      primes,
//      randomSeries
//    );
//    dataOutputer(binarySearchTime, primes->size(), numSearches, "binarySearchTime");

//    std::vector<double> binaryTreeSearchTime = measureSearchTime(
//      [](const void* root, int target) -> int {
//        return binaryTreeSearch(static_cast<const Node*>(root), target);
//      },
//      binaryTree,
//      randomSeries
//    );
//    dataOutputer(binaryTreeSearchTime, primes->size(), numSearches, "binaryTreeSearchTime");

    std::vector<double> hashSearchTime = measureSearchTime(
      [](const void* table, int target) -> int {
        return hashSearch(*static_cast<const std::vector<HashNode*>*>(table), target);
      },
      &hashTable,
      randomSeries
    );
    dataOutputer(hashSearchTime, primes->size(), numSearches, "hashSearchTime");
  }
}