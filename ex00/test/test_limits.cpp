#include <iostream>
#include <limits>
#include <iomanip>

template<typename T>
void showMinMax() {
  if (typeid(T) == typeid(char)) {
    std::cout << "min: " << static_cast<int>(std::numeric_limits<T>::min()) << std::endl;
    std::cout << "max: " << static_cast<int>(std::numeric_limits<T>::max()) << std::endl;
  } else if (typeid(T) == typeid(float)) {
    std::cout << "min: " << std::fixed << std::setprecision(150) << std::numeric_limits<T>::min() << std::endl;
    std::cout << "max: " << std::fixed << std::setprecision(1) << std::numeric_limits<T>::max() << std::endl;
  } else if (typeid(T) == typeid(double)) {
    std::cout << "min: " << std::fixed << std::setprecision(1050) << std::numeric_limits<T>::min() << std::endl;
    std::cout << "max: " << std::fixed << std::setprecision(1) << std::numeric_limits<T>::max() << std::endl;
  } else {
    std::cout << "min: " << std::numeric_limits<T>::min() << std::endl;
    std::cout << "max: " << std::numeric_limits<T>::max() << std::endl;
  }
  std::cout << std::endl;
}

int main() {

  std::cout << "char:" << std::endl;
  showMinMax<char>();
  std::cout << "int:" << std::endl;
  showMinMax<int>();
  std::cout << "long:" << std::endl;
  showMinMax<long>();
  std::cout << "float:" << std::endl;
  showMinMax<float>();
  std::cout << "double:" << std::endl;
  showMinMax<double>();
}
