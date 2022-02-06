#include "Identifier.hpp"

#include <iostream>

Base* generate(void) {
  srand(time(NULL));
  int random_num = rand() % 3;
  switch (random_num) {
  case 0:
    return new A();
    break;
  case 1:
    return new B();
    break;
  case 2:
    return new C();
    break;
  default:
    return NULL;
    break;
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C*>(p)) {
    std::cout << "C" << std::endl;
  } else {
    std::cout << "Base" << std::endl;
  }
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
  } catch (const std::exception&) {
    try {
      (void)dynamic_cast<B&>(p);
      std::cout << "B" << std::endl;
    } catch (const std::exception&) {
      try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
      } catch (const std::exception&) {
        std::cout << "Base" << std::endl;
      }
    }
  }
}
