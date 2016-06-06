#ifndef INSTRUMENTED_H
#define INSTRUMENTED_H

#include <cstddef>

// instrumented_base holds the static array of counts
struct instrumented_base
{
  enum operations {
    n, copy, assignment, destructor, default_constructor, equality, comparison, construction
  };
  static const size_t number_ops = 8;
  static double counts[number_ops];
  static const char* counter_names[number_ops];
  static void initialize(size_t);
};

// T -> instrumented<T>
template <typename T>
// Semiregular(T) || Regular(T) || TotallyOrdered(T)

struct instrumented : instrumented_base
{
  // Data (for type functions):
  typedef T value_type;

  // Data (for real):
  T value;

  // Conversion functions:
  explicit instrumented(const T& x) : value(x) { ++counts[construction]; }

  // ops to make the instrumented Semiregular:
  // copy constructor:
  instrumented(const instrumented& x) : value(x.value) { ++counts[copy]; }
  // default constructor:
  instrumented() { ++counts[default_constructor]; }
  // destructor:
  ~instrumented() { ++counts[destructor]; }
  // assignment:
  instrumented& operator=(const instrumented& x) {
    ++counts[assignment];
    value = x.value;
    return *this;
  }

  // ops to make the instrumented Regular:
  // equality:
  friend // so that it's symmetric in its args
  bool operator==(const instrumented& x, const instrumented& y) {
    ++counts[equality];
    return x.value == y.value;
  }
  // inequality (not implicit... ARGH!!!):
  friend
  bool operator!=(const instrumented& x, const instrumented& y) {
    return !(x == y);
  }
  
  // ops to make the instrumented TotallyOrdered:
  // less-than is primary; the rest should be implicit, but aren't:
  friend
  bool operator<(const instrumented& x, const instrumented& y) {
    ++counts[comparison];
    return x.value < y.value;
  }
  friend
  bool operator>(const instrumented& x, const instrumented& y) {
    return y < x;
  }
  friend
  bool operator<=(const instrumented& x, const instrumented& y) {
    return !(y < x);
  }
  friend
  bool operator>=(const instrumented& x, const instrumented& y) {
    return !(x < y);
  }
};
#endif
