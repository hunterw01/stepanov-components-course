#ifndef UNIT_H
#define UNIT_H

// T -> {T}
template <typename T>
// Semiregular(T) || Regular(T) || TotallyOrdered(T)
struct unit
{
  // Data (for type functions):
  typedef T value_type;

  // No real Data!

  // Conversion functions (NOT implicit):
  explicit unit(const T& x) {}

  // ops to make the unit Semiregular:
  // copy constructor (could be implicitly declared):
  unit(const unit& x) {}
  // default constructor (implicit ONLY if no other c'structors):
  unit() {}
  // destructor (could be implicitly declared):
  ~unit()
  // assignment (could be implicitly declared):
  unit& operator=(const unit& x) {
    value = x.value;
    return *this;
  }

  // ops to make the unit Regular:
  // equality (can be implicit in 2040 [maybe]):
  friend // so that it's symmetric in its args
  bool operator==(const unit& x, const unit& y) {
    return x.value == y.value;
  }
  // inequality (not implicit... ARGH!!!):
  friend
  bool operator!=(const unit& x, const unit& y) {
    return !(x == y);
  }
  
  // ops to make the unit TotallyOrdered:
  // less-than is primary; the rest should be implicit, but aren't:
  friend
  bool operator<(const unit& x, const unit& y) {
    return x.value < y.value;
  }
  friend
  bool operator>(const unit& x, const unit& y) {
    return y < x;
  }
  friend
  bool operator<=(const unit& x, const unit& y) {
    return !(y < x);
  }
  friend
  bool operator>=(const unit& x, const unit& y) {
    return !(x < y);
  }
};
#endif
