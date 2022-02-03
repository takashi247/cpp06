#include <iostream>
#include "StringConverter.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Error: Please provide one argument" << std::endl;
    exit(EXIT_FAILURE);
  }
  const std::string str = av[1];
  StringConverter s_converter(str);
  s_converter.setValueType();
  s_converter.createBaseValue();
  s_converter.convertToOtherTypes();
  s_converter.printValues();
}
