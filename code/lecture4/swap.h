
template <typename T>
// requires T to be Semiregular
// horribly slow, when T is a container
inline
void swap(T& a, T& b){
  T tmp(a);
  a = b;
  b = tmp;
}

/*
the slowness:
std::vector<int> a(1000000);
std::vector<int> b(1000000);
swap(a, b);
this is like 3000000 instructions.
this should be like 10 instructions.
we should just swap the info in the
headers, and maybe some back pointers.
(there are 3 pointers in a vector,
one in a linked list, etc...)
*/

template <typename T>
// requires T to be UnsignedIntegral
// uses no extra (temp) memory
inline
void swap_xor(T& a, T& b){
  if(&a != &b){
    a = a ^ b; // a ^ b, b
    b = a ^ b; // a ^ b, a
    a = a ^ b; // b, a
  }
}
/*
// Partial specialization
// Needs to be friend of vector... and ugh namespaces
template <typename T>
inline
void swap(std::vector<T>& a, std::vector<T>& b){
  // swap headers of a and b
  // fix back pointers (if they exist)
}
*/
