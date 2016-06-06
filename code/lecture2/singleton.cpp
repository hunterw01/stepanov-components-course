#include "singleton.h"
#include <iostream>

typedef singleton<double> sd;
typedef singleton<int> si;

int main() {
  sd x(1.5);
  sd y(2.5);
  si z(1);
  std::cout << double(x + x) << std::endl;
  std::cout << double(x + y + y) << std::endl;
  std::cout << int(z + z) << std::endl;

}
  
  
