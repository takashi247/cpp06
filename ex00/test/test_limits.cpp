#include <iostream>
#include <limits>
#include <iomanip>

template<typename T>
void showMinMax() {
  if (typeid(T) == typeid(char)) {
    std::cout << "min: " << static_cast<int>(std::numeric_limits<T>::min()) << std::endl;
    std::cout << "max: " << static_cast<int>(std::numeric_limits<T>::max()) << std::endl;
  } else if (typeid(T) == typeid(float)) {
    std::cout << "min: " << std::fixed << std::setprecision(1) << static_cast<int>(std::numeric_limits<T>::min()) << std::endl;
    std::cout << "max: " << std::fixed << std::setprecision(150) << static_cast<int>(std::numeric_limits<T>::max()) << std::endl;
  } else if (typeid(T) == typeid(double)) {
    std::cout << "min: " << std::fixed << std::setprecision(1) << static_cast<int>(std::numeric_limits<T>::min()) << std::endl;
    std::cout << "max: " << std::fixed << std::setprecision(1050) << static_cast<int>(std::numeric_limits<T>::max()) << std::endl;
  } else {
    std::cout << "min: " << std::numeric_limits<T>::min() << std::endl;
    std::cout << "max: " << std::numeric_limits<T>::max() << std::endl;
  }
  std::cout << std::endl;
}

int main() {

  std::cout << "char:" << std::endl;
  showMinMax<char>();
  std::cout << "short:" << std::endl;
  showMinMax<short>();
  std::cout << "int:" << std::endl;
  showMinMax<int>();
  std::cout << "long:" << std::endl;
  showMinMax<long>();
  std::cout << "float:" << std::endl;
  showMinMax<float>();
  std::cout << "double:" << std::endl;
  showMinMax<double>();
  std::cout << "long double:" << std::endl;
  showMinMax<long double>();
  std::cout << "unsigned short:" << std::endl;
  showMinMax<unsigned short>();
  std::cout << "unsigned int:" << std::endl;
  showMinMax<unsigned int>();
  std::cout << "unsigned long:" << std::endl;
  showMinMax<unsigned long>();
}
