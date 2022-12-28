//
// Created by nordi on 12/23/2022.
//

#ifndef DOA_LABORATION02_SORTALGORITHMER_H
#define DOA_LABORATION02_SORTALGORITHMER_H

#include <vector>

namespace doa_laboration02 {
  // Function to perform insertion sort
  void insertion_sort(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
      int key = arr[i];
      int j = i - 1;

      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = key;
    }
  }

  // Function to perform selection sort
  void selection_sort(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
      int min_index = i;
      for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[min_index]) {
          min_index = j;
        }
      }
      std::swap(arr[i], arr[min_index]);
    }
  }

// quick sort partition
  int partition(std::vector<int> &arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
      if (arr[j] < pivot) {
        i++;
        std::swap(arr[i], arr[j]);
      }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
  }

// Quick sort using a right pivot
  void quick_sort_right_pivot(std::vector<int> &arr, int left, int right) {
    // Add base case for arrays with fewer than two elements
    if (left >= right) {
      return;
    }

    int pivot = partition(arr, left, right);
    quick_sort_right_pivot(arr, left, pivot - 1);
    quick_sort_right_pivot(arr, pivot + 1, right);
  }

// Quick sort using a right pivot with one parameter to fit signature
  void quick_sort_right_pivot(std::vector<int> &arr) {
    quick_sort_right_pivot(arr, 0, arr.size() - 1);
  }

  // Quick sort middle of three pivot
  void quick_sort_mot_pivot(std::vector<int> &arr, int left, int right) {
    if (left < right) {
      int mid = left + (right - left) / 2;
      int pivot = arr[mid];
      if (arr[left] > pivot) {
        std::swap(arr[left], arr[mid]);
      }
      if (arr[right] < pivot) {
        std::swap(arr[right], arr[mid]);
      }
      if (arr[left] > arr[right]) {
        std::swap(arr[left], arr[right]);
      }
      int i = left + 1;
      int j = right - 2;
      while (true) {
        while (arr[i] < pivot) {
          i++;
        }
        while (arr[j] > pivot) {
          j--;
        }
        if (i < j) {
          std::swap(arr[i], arr[j]);
          i++;
          j--;
        } else {
          break;
        }
      }
      std::swap(arr[i], arr[right - 1]);
      int partition_index = i;
      quick_sort_mot_pivot(arr, left, partition_index - 1);
      quick_sort_mot_pivot(arr, partition_index + 1, right);
    }
  }

  // Quick sort using a middle-of-three pivot with one parameter to fit signature
  void quick_sort_mot_pivot(std::vector<int> &arr) {
    quick_sort_mot_pivot(arr, 0, arr.size() - 1);
  }
  // Quick sort using a middle-of-three pivot with one parameter to fit signature
  void stdSort(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());
  }
} // doa_laboration02

#endif //DOA_LABORATION02_SORTALGORITHMER_H