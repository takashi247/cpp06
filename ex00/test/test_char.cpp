#include <iostream>

#include <stdio.h>

int main() {
  signed char a = 1;
  while (a) {
    std::cout << static_cast<int>(a) << " = " << a << std::endl;
    ++a;
  }
  // 0 is NULL
  std::cout << static_cast<int>(a) << " = NULL" << std::endl;
}
