#include "C.hpp"

#include <iostream>

C::C() {}

C::C(C const &other) { *this = other; }

C &C::operator=(C const &other) {
  (void)other;
  return *this;
}

C::~C() {}
