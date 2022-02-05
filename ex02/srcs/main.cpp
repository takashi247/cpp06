#include "Identifier.hpp"

int main() {
  Base* random_instance = generate();
  identify(random_instance);
  identify(*random_instance);
  delete random_instance;
}

#ifdef LEAKS
void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void) {
  system("leaks -q a.out");
}
#endif
