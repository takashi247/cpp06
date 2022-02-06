#include "Identifier.hpp"

#include <iostream>

int main() {
  Base* random_instance = generate();
  std::cout << "Check 'void identify(Base* p)': ";
  identify(random_instance);
  std::cout << "Check 'void identify(Base& p)': ";
  identify(*random_instance);
  delete random_instance;
}

#ifdef LEAKS
void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void) {
  system("leaks -q a.out");
}
#endif
