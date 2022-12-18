//
// Created by nordi on 11/18/2022.
//

#include <algorithm>
#include "int_buffer.h"

namespace metodik_laboration01 {
    int_buffer::int_buffer(size_t size) :
            buffer(new int[size]), bufferEnd(buffer + size) {
    }

    int_buffer::int_buffer(const int *source, size_t size) :
            int_buffer(size) {
        std::copy(source, source + size, buffer);
    }

    int_buffer::int_buffer(const int_buffer &rhs) :
            int_buffer(rhs.buffer, rhs.size()) {
    }

    int_buffer::int_buffer(int_buffer &&rhs) noexcept :
            buffer(nullptr), bufferEnd(nullptr) {
        swap(rhs);
    }

//    int_buffer &int_buffer::operator=(const int_buffer &rhs) {
//        return *this;
//    }
//
//    int_buffer &int_buffer::operator=(int_buffer &&rhs) {
//        return *this;
//    }

    // we trust the compiler to choose the right way to handle rhs
    int_buffer &int_buffer::operator=(int_buffer rhs) {
        swap(rhs);
        return *this;
    }

    int &int_buffer::operator[](size_t index) {
        return buffer[index];
    }

    const int &int_buffer::operator[](size_t index) const {
        return buffer[index];
    }

    size_t int_buffer::size() const {
        return this->bufferEnd - this->buffer;
    }

    int *int_buffer::begin() {
        return this->buffer;
    }

    int *int_buffer::end() {
        return this->bufferEnd;
    }

    const int *int_buffer::begin() const {
        return this->buffer;
    }

    const int *int_buffer::end() const {
        return this->bufferEnd;
    }

    void int_buffer::swap(int_buffer &rhs) {
        std::swap(this->buffer, rhs.buffer);
        std::swap(this->bufferEnd, rhs.bufferEnd);
    }


    int_buffer::~int_buffer() {
        delete[] buffer;
    }


} // metodik_laboration01