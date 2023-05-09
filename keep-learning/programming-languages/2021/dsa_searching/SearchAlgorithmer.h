//
// Created by nordin on 05/07/2023.
//

#ifndef DOA_LABORATION03_SEARCHALGORITHMER_H
#define DOA_LABORATION03_SEARCHALGORITHMER_H

#include <vector>

namespace doa_laboration03 {
  int sequentialSearch(const std::vector<int> &arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == target) {
        return i;
      }
    }
    return -1; // if target not found
  }

  // binary searching in a sorted array recursively
  int binarySearch(const std::vector<int> &arr, int low, int high, int target) {
    if (high < low) {
      return -1;
    }
    int mid = low + (high - low) / 2;

    if (target == arr[mid]) {
      return mid;
    }

    if (target > arr[mid]) {
      return binarySearch(arr, mid + 1, high, target);
    }

    if (target < arr[mid]) {
      return binarySearch(arr, low, mid - 1, target);
    }
  }


  // binary searching in a sorted array iteratively - needed to adhere to the function signature requirements
  int binarySearch(const std::vector<int> &arr, int target) {
    return binarySearch(arr, 0, arr.size() - 1, target);
  }

  int binaryTreeSearch(const Node *root, int target) {
    if (root == nullptr) {
      return -1;
    }
    if (root->data == target) {
      return root->data;
    } else if (target < root->data) {
      return binaryTreeSearch(root->left, target);
    } else if (target > root->data) {
      return binaryTreeSearch(root->right, target);
    } else {
      return -1;
    }
  }

  int hashSearch(const std::vector<HashNode *> &hashTable, int target) {
    int index = target % hashTable.size();
    HashNode *node = hashTable[index];
    while (node != nullptr) {
      if (node->data == target) {
        return node->data;
      }
      node = node->next;
    }
    return -1;
  }
} // doa_laboration03

#endif //DOA_LABORATION03_SEARCHALGORITHMER_H