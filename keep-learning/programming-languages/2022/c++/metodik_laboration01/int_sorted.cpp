//
// Created by nordi on 11/20/2022.
//

#include "int_sorted.h"
#include <algorithm>

namespace metodik_laboration01 {
  int_sorted::int_sorted(const int *source, size_t size) : buffer(source, size) {
    if (size > 1) {
      buffer = std::move(sort(begin(), end()).buffer);
    }
  }
  size_t int_sorted::size() const {
    return buffer.size();
  }
  const int *int_sorted::begin() const {
    return buffer.begin();
  }
  const int *int_sorted::end() const {
    return buffer.end();
  }
  int_sorted int_sorted::merge(const int_sorted &merge_with) const {
    const auto *thisItr = begin();
    const auto *mergeWithItr = merge_with.begin();
    int_buffer mergeWithBuffer(size() + merge_with.size());
    auto *resultItr = mergeWithBuffer.begin();

    while (thisItr != end() && mergeWithItr != merge_with.end()) {
      if (*thisItr < *mergeWithItr)
        *resultItr++ = *thisItr++;
      else
        *resultItr++ = *mergeWithItr++;
    }
    while (thisItr != end())
      *resultItr++ = *thisItr++;
    while (mergeWithItr != merge_with.end())
      *resultItr++ = *mergeWithItr++;

    int_sorted sortedResult(nullptr, 0);
    sortedResult.buffer = std::move(mergeWithBuffer);
    return sortedResult;
  }
  int_sorted int_sorted::sort(const int *begin, const int *end) {
    if (begin == end) return {nullptr, 0};
    if (begin == end - 1) return {begin, 1};
    ptrdiff_t half = (end - begin) / 2;
    const int *mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
  }
  const int &int_sorted::operator[](size_t index) const {
    return buffer[index];
  }
  void int_sorted::insert(int value) {
    buffer = merge(int_sorted(&value, 1)).buffer;
  }
  int_buffer int_sorted::getBuffer() const {
    return buffer;
  }
}// namespace metodik_laboration01