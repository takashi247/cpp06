#include <iostream>
#include "StringConverter.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Error: Please provide one argument" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string str = av[1];
  StringConverter s_converter(str);

  s_converter.printValues();
}

/* sandbox main function

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Error: Please provide one argument" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string str = av[1];

  {
    std::cout << "\n---test with istringstream---" << std::endl;

    std::istringstream iss(str);
    int num;
    iss >> num;

    std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << static_cast<float>(num) << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
  }
  {
    std::cout << "\n---test with string class functions---" << std::endl;

    int i_num = std::stoi(str);
    float f_num = std::stof(str);
    double d_num = std::stod(str);

    std::cout << "char: '" << static_cast<char>(i_num) << "'" << std::endl;
    std::cout << "int: " << i_num << std::endl;
    std::cout << "float: " << f_num << std::endl;
    std::cout << "double: " << d_num << std::endl;
  }
  std::cout << std::endl;
}

*/
