#include <iostream>
#include <string>
#include <cerrno>
#include <cstdlib>
#include <iomanip>

int main(int ac, char **av) {
  if (ac != 2) {
    return (EXIT_FAILURE);
  }
  std::cout << std::endl;
  std::cout << "*---Result of strtol---*" << std::endl;
  char *str_end_l;
  long num_long = std::strtol(av[1], &str_end_l, 10);
  std::cout << "Input string: " << std::string(av[1], str_end_l - av[1]) << std::endl;
  if (errno == ERANGE) {
    std::cout << "  **range error**" << std::endl;
    errno = 0;
  }
  std::cout << "  char: " << static_cast<char>(num_long) << std::endl;
  std::cout << "  int: " << static_cast<int>(num_long) << std::endl;
  std::cout << "  float: " << static_cast<float>(num_long) << std::endl;
  std::cout << "  double: " << num_long << std::endl;
  std::cout << "  *str_end_l = " << *str_end_l << std::endl;
  std::cout << "  *(str_end_l + 1) == \'\\0\' >> " << std::boolalpha << (*(str_end_l + 1) == '\0') << std::endl;
  std::cout << "  std::isdigit(*(str_end_l + 1) = " << std::boolalpha << (std::isdigit(static_cast<unsigned char>(*(str_end_l + 1))) == 1) << std::endl;
  std::cout << std::endl;
  std::cout << "*---Result of strtod---*" << std::endl;
  char *str_end_d;
  double num_dbl = std::strtod(av[1], &str_end_d);
  std::cout << "Input string: " << std::string(av[1], str_end_d - av[1]) << std::endl;
  if (errno == ERANGE) {
    std::cout << "  **range error**" << std::endl;
    errno = 0;
  }
  std::cout << "  char: " << static_cast<char>(num_dbl) << std::endl;
  std::cout << "  int: " << static_cast<int>(num_dbl) << std::endl;
  std::cout << "  float: " << static_cast<float>(num_dbl) << std::endl;
  std::cout << "  double: " << num_dbl << std::endl;
  std::cout << "  *str_end_d = " << *str_end_d << std::endl;
  std::cout << "  char == double?: " << std::boolalpha << (static_cast<char>(num_dbl) == num_dbl) << std::endl;
  std::cout << "  int == double?: " << std::boolalpha << (static_cast<int>(num_dbl) == num_dbl) << std::endl;
  std::cout << "  float == double?: " << std::boolalpha << (static_cast<float>(num_dbl) == num_dbl) << std::endl;
  std::cout << std::endl;
}
