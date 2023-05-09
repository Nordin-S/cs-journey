//
// Created by nordin on 05/07/2023.
//

#ifndef DATAGENERATOR_HPP
#define DATAGENERATOR_HPP

#include <vector>
#include <algorithm>

#include <ctime>
#include <algorithm>
#include <cmath>
#include "DataGenerator.h"

namespace doa_laboration03 {
  struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) :data(data), left(nullptr), right(nullptr) {};
  };

  Node* newNode(int value) {
    return new Node(value);
  }

  struct HashNode {
    int data;
    HashNode* next;

    HashNode(int data) :data(data), next(nullptr) {};
  };

  HashNode* newHashNode(int value) {
    return new HashNode(value);
  }

// Helper function to check if a number is prime
  bool isPrime(int number) {
    if (number < 2) {
      return false;
    }
    for (int i = 2; i <= sqrt(number); i++) {
      if (number % i == 0) {
        return false;
      }
    }
    return true;
  }

// Helper function generates list of random numbers to search for
  std::vector<int> generateRandomSeries(int size, int minValue, int maxValue) {
    std::srand(time(nullptr));
    std::vector<int> values;
    for (int i = 0; i < size; i++) {
      int value = rand() % (maxValue - minValue + 1) + minValue;
      values.push_back(value);
    }
    return values;
  }

// Helper function creates balanced binary tree from int vector
  Node* createBalancedBinaryTree(const std::vector<int>& primes, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    int mid = (start + end) / 2;
    Node* currentRoot = newNode(primes[mid]);

    currentRoot->left = createBalancedBinaryTree(primes, start, mid - 1);
    currentRoot->right = createBalancedBinaryTree(primes, mid + 1, end);

    return currentRoot;
  }

  Node* createBalancedBinaryTree(const std::vector<int>& primes) {
    return createBalancedBinaryTree(primes, 0, primes.size() - 1);
  }

// helper function to insert into hash table
  void hashNodeInsert(std::vector<HashNode*>& hashTable, int value) {
    int index = value % hashTable.size();
    HashNode* newNode = newHashNode(value);

    if (hashTable[index] == nullptr) {
      hashTable[index] = newNode;
    } else {
      HashNode* current = hashTable[index];
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
    }
  }

  std::vector<HashNode*> hashTableFromPrimes(const std::vector<int>& primes) {
    int reserved_size = primes.size() * 2; // To ensure a load factor below 50%
    std::vector<HashNode*> hashTable(reserved_size, nullptr);
    for (int prime : primes) {
      hashNodeInsert(hashTable, prime);
    }
    return hashTable;
  }

  // generate vector with primes given a size limit starting from 2
  std::vector<int>* generatePrimeSeries(int limit) {
    auto* primes = new std::vector<int>;
    for (int i = 2; i <= limit; i++) {
      if (isPrime(i)) {
        primes->push_back(i);
      }
    }
    return primes;
  }

//  Node* binarySearchTree(std::vector<int>* vector, int start, int stop);
//  std::vector<HashNode*>* hashTable(std::vector<int>* vector);
} // doa_laboration03
#endif// doa_laboration03
