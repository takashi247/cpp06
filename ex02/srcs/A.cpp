#include "A.hpp"

#include <iostream>

A::A() {}

A::A(A const &other) { *this = other; }

A &A::operator=(A const &other) {
  (void)other;
  return *this;
}

A::~A() {}
