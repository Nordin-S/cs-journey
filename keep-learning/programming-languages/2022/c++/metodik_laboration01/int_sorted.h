//
// Created by nordi on 11/20/2022.
//

#ifndef METODIK_LABORATION01_INT_SORTED_H
#define METODIK_LABORATION01_INT_SORTED_H

#include "int_buffer.h"
#include <cstddef>

namespace metodik_laboration01 {
  class int_sorted{
public:
    int_sorted() = delete;
    int_sorted(const int *source, size_t size);
    [[nodiscard]] size_t size() const;
    void insert(int value);
    [[nodiscard]] const int *begin() const;
    [[nodiscard]] const int *end() const;
    [[nodiscard]] int_sorted merge(const int_sorted &merge_with) const;
    int_sorted sort(const int *begin, const int *end);
    const int &operator[](size_t index) const;
    int_buffer getBuffer() const;

private:
    int_buffer buffer;
  };

}// namespace metodik_laboration01

#endif//METODIK_LABORATION01_INT_SORTED_H
