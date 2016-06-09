#ifndef SINGLETON_H
#define SINGLETON_H

// T -> {T}
template <typename T>
// Semiregular(T) || Regular(T) || TotallyOrdered(T)
struct singleton
{
  // Data (for type functions):
  typedef T value_type;

  // Data (for real):
  T value;

  // Conversion functions (NOT implicit):
  explicit singleton(const T& x) : value(x) {}
  explicit operator T() const { return value; }

  // ops to make the singleton Semiregular:
  // copy constructor (could be implicitly declared):
  singleton(const singleton& x) : value(x.value) {}
  // default constructor (implicit ONLY if no other c'structors):
  singleton() {}
  // destructor (could be implicitly declared):
  ~singleton() {}
  // assignment (could be implicitly declared):
  singleton& operator=(const singleton& x) {
    value = x.value;
    return *this;
  }

  // ops to make the singleton Regular:
  // equality (can be implicit in 2040 [maybe]):
  friend // so that it's symmetric in its args
  bool operator==(const singleton& x, const singleton& y) {
    return x.value == y.value;
  }
  // inequality (not implicit... ARGH!!!):
  friend
  bool operator!=(const singleton& x, const singleton& y) {
    return !(x == y);
  }
  
  // ops to make the singleton TotallyOrdered:
  // less-than is primary; the rest should be implicit, but aren't:
  friend
  bool operator<(const singleton& x, const singleton& y) {
    return x.value < y.value;
  }
  friend
  bool operator>(const singleton& x, const singleton& y) {
    return y < x;
  }
  friend
  bool operator<=(const singleton& x, const singleton& y) {
    return !(y < x);
  }
  friend
  bool operator>=(const singleton& x, const singleton& y) {
    return !(x < y);
  }
};
#endif
