//
// Created by nordi on 12/8/2022.
//

#ifndef METODIK_LABORATION05_PREDICATE_H
#define METODIK_LABORATION05_PREDICATE_H
#include <functional>

namespace metodik_laboration05 {

  template<typename T>
  class Predicate {
public:
    using MemFn = std::function<double(const T &)>;

    Predicate() = default;
    Predicate(MemFn mem_fn, double threshold);
    bool operator()(const T &value) const;
    bool operator()(const T &lhs, const T &rhs) const;

private:
    MemFn m_fn;
    double m_threshold;
  };

  template<typename T>
  Predicate<T>::Predicate(MemFn mem_fn, double threshold) : m_fn(mem_fn), m_threshold(threshold) {}

  template<typename T>
  bool Predicate<T>::operator()(const T &value) const {
    return m_fn(value) > m_threshold;
  }
  template<typename T>
  bool Predicate<T>::operator()(const T &lhs, const T &rhs) const {
    return lhs == rhs;
  }
}// namespace metodik_laboration05

#endif//METODIK_LABORATION05_PREDICATE_H
