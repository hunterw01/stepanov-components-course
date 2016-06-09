#include "swap.h"

/*
we should be able to write things like:
min<int, std::greater<int> >
min<int>
these are types, but the second form
requires a wrapper (defined below)
*/

template <typename T>
// requires T to be TotallyOrdered
struct less{
  inline bool operator()(const T& a, const T& b) const {
    return a < b;
  }
};

template <typename T, typename Compare>
// requires Compare to be a StrictWeakOrdering on T
inline
const T& min(const T& a, const T& b, Compare cmp){
  if (cmp(b, a))
    return b;
  return a;
}

template <typename T>
inline
const T& min(const T& a, const T& b) {
  return min(a, b, less<T>());
}

template <typename T, typename Compare>
// requires Compare to be a StrictWeakOrdering on T
inline
const T& max(const T& a, const T& b, Compare cmp){
  if (cmp(b, a))
    return a;
  return b;
}

template <typename T>
inline
const T& max(const T& a, const T& b) {
  return max(a, b, less<T>());
}

template <typename T, typename Compare>
// requires Compare to be a StrictWeakOrdering on T
inline
void sort2(const T& a, const T& b, Compare cmp){
  if(cmp(b, a))
    swap(a, b);
}

template <typename I, typename Compare>
// requires I to be a ForwardIterator, and
// Compare to be a StrictWeakOrdering on value_type<I>
inline
I min_element(I first, I last, Compare cmp) {
  if(first == last) return last;
  I min_el = first;
  while(++first != last)
    if(cmp(*first, *min_el)) min_el = first;
  return min_el;
}

// Not right yet...
template <typename I, typename Compare>
// requires I to be a ForwardIterator, and
// Compare to be a StrictWeakOrdering on value_type<I>
inline
I max_element(I first, I last, Compare cmp) {
  if(first == last) return last;
  I max_el = first;
  while(++first != last)
    if(!cmp(*first, *max_el)) max_el = first;
  return max_el;
}
