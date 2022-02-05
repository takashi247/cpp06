#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include <stdlib.h> // for using srand, rand, and NULL
#include <time.h> // for time

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif // IDENTIFIER_HPP
