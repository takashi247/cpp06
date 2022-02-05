#include "B.hpp"

#include <iostream>

B::B() {}

B::B(B const &other) { *this = other; }

B &B::operator=(B const &other) {
  (void)other;
  return *this;
}

B::~B() {}
