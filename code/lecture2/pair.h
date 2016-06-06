#ifndef PAIR_H
#define PAIR_H

// T0 -> T1 -> {T0, T1}
template <typename T0, typename T1>
// is the associativity of the ands and ors right here?:
// ( Semiregular(T0) || Regular(T0) || TotallyOrdered(T0) )
// && ( Semiregular(T1) || Regular(T1) || TotallyOrdered(T1) )
struct pair
{
  // Data (for type functions):
  typedef T0 value_type_0;
  typedef T1 value_type_1;

  // Data (for real):
  T0 m0;
  T1 m1;

  // Conversion functions (NOT implicit):
  explicit pair(const T0& x, const T1& y) : m0(x), m1(y) {}
  explicit operator T0() const { return m0; }
  explicit operator T1() const { return m1; }

  // ops to make the pair Semiregular:
  // copy constructor (could be implicitly declared):
  pair(const pair& x) : m0(x.m0), m1(x.m1) {}
  // default constructor (implicit ONLY if no other c'structors):
  pair() {}
  // destructor (could be implicitly declared):
  ~pair()
  // assignment (could be implicitly declared):
  pair& operator=(const pair& x) {
    m0 = x.m0;
    m1 = x.m1;
    return *this;
  }

  // ops to make the pair Regular:
  // equality (can be implicit in 2040 [maybe]):
  friend // so that it's symmetric in its args
  bool operator==(const pair& x, const pair& y) {
    return (x.m0 == y.m0) && (x.m1 == y.m1);
  }
  // inequality (not implicit... ARGH!!!):
  friend
  bool operator!=(const pair& x, const pair& y) {
    return !(x == y);
  }
  
  // ops to make the pair TotallyOrdered:
  // less-than is primary; the rest should be implicit, but aren't:
  friend
  bool operator<(const pair& x, const pair& y) {
    return x.value < y.value;
  }
  friend
  bool operator>(const pair& x, const pair& y) {
    return y < x;
  }
  friend
  bool operator<=(const pair& x, const pair& y) {
    return !(y < x);
  }
  friend
  bool operator>=(const pair& x, const pair& y) {
    return !(x < y);
  }
};
#endif
