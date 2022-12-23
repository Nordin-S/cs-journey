//
// Created by nordi on 11/18/2022.
//

#ifndef METODIK_LABORATION01_INT_BUFFER_H
#define METODIK_LABORATION01_INT_BUFFER_H

#include <cstddef>

namespace metodik_laboration01 {

  class int_buffer {

public:
    int_buffer() = delete;                     // delete default CTOR
    explicit int_buffer(size_t size);          // CTOR
    int_buffer(const int *source, size_t size);// CTOR
    int_buffer(const int_buffer &rhs);         //copy CTOR
    int_buffer(int_buffer &&rhs) noexcept;     //move CTOR

    //        int_buffer &operator=(const int_buffer &rhs);// copy assign
    //        int_buffer &operator=(int_buffer &&rhs);// move assign
    // we trust the compiler to choose the right way to handle rhs
    int_buffer &operator=(int_buffer rhs);// thus we have rule 4.5,
    int &operator[](size_t index);
    const int &operator[](size_t index) const;
    [[nodiscard]] size_t size() const;
    int *begin();
    int *end();
    [[nodiscard]] const int *begin() const;
    [[nodiscard]] const int *end() const;
    ~int_buffer();

private:
    int *buffer;
    int *bufferEnd;
    void swap(int_buffer &rhs);
  };

}// namespace metodik_laboration01

#endif//METODIK_LABORATION01_INT_BUFFER_H
