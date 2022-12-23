#include "algorithm"
#include "int_buffer.h"
#include "int_sorted.h"
#include <chrono>
#include <iostream>
using namespace metodik_laboration01;

void f(int_buffer buf);
//void printSorted(const int_sorted &sortedBuf);
bool isSorted(int_buffer buf);
void timeMergeSort(int_buffer &buf);
void timeSelectionSort(int_buffer &buf);
void timeStdSort(int_buffer &buf);


int main() {
  srand(time(nullptr));
  f(int_buffer(10));
  int_buffer buf01(100000);
  std::generate(buf01.begin(), buf01.end(), rand);
  int_buffer bufferToBeSorted2(buf01.begin(), buf01.size());
  int_buffer bufferToBeSorted3(buf01.begin(), buf01.size());

//  timeSelectionSort(bufferToBeSorted2);
  timeStdSort(bufferToBeSorted3);
  timeMergeSort(buf01);
}
void f(int_buffer buf) {
  int count = 1;
  for (int *i = buf.begin(); i != buf.end(); i++)
    *i = count++;

  for (const int *i = buf.begin(); i != buf.end(); i++)
    std::cout << *i << ", ";
  std::cout << std::endl;

  for (auto e: buf)
    std::cout << e << ", ";
  std::cout << std::endl;
  std::cout << "======================================" << std::endl;
}
void printSorted(const int_sorted &sortedBuf) {
  for (auto i: sortedBuf)
    std::cout << i << ", ";
  std::cout << std::endl;
  std::cout << "======================================" << std::endl;
}
bool isSorted(int_buffer buf) {
  auto const *currentItr = buf.begin();
  auto const *nextItr = buf.begin() + 1;
  while (nextItr != buf.end()) {
    if (*currentItr++ > *nextItr++) {
      std::cout << "buffer is not sorted: " << std::endl;
      return false;
    }
  }
  std::cout << "buffer is sorted: " << std::endl;
  std::cout << "======================================" << std::endl;
  return true;
}

void timeMergeSort(int_buffer &buf) {
  std::cout << "Sorting using merge sort: " << std::endl;
  auto timeStart = std::chrono::steady_clock::now();
  int_sorted bufferToBeSorted(buf.begin(), buf.size());
  auto timeEnd = std::chrono::steady_clock::now();
  auto timeTotal = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);
  std::cout << "Sorting done with duration: " << timeTotal.count() << " ms" << std::endl;
  isSorted(bufferToBeSorted.getBuffer());
  //  printSorted(buf);
}
void timeSelectionSort(int_buffer &buf) {
  std::cout << "Sorting using selection sort: " << std::endl;
  auto timeStart = std::chrono::steady_clock::now();
  for (int *i = buf.begin(); i < buf.end() - 1; ++i) {
    int *min = i;
    for (int *j = i + 1; j < buf.end(); ++j) {
      if (*min > *j)
        min = j;
    }
    std::swap(*min, *i);
  }
  auto timeEnd = std::chrono::steady_clock::now();
  auto timeTotal = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);
  std::cout << "Sorting done with duration: " << timeTotal.count() << " ms" << std::endl;
  isSorted(buf);
  //  printSorted(buf);
}
void timeStdSort(int_buffer &buf) {
  std::cout << "Sorting using std sort: " << std::endl;
  auto timeStart = std::chrono::steady_clock::now();
  std::sort(buf.begin(), buf.end());
  auto timeEnd = std::chrono::steady_clock::now();
  auto timeTotal = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);
  std::cout << "Sorting done with duration: " << timeTotal.count() << " ms" << std::endl;
  isSorted(buf);
  //  printSorted(buf);
}
