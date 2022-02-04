#ifndef STRINGCONVERTER_HPP
#define STRINGCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <limits>

class StringConverter {
 public:
  StringConverter(const std::string &str);
  virtual ~StringConverter();

  void setValueType();
  void createBaseValue();
  void convertToOtherTypes();
  const std::stringstream &getCharOS() const;
  const std::stringstream &getIntOS() const;
  const std::stringstream &getFloatOS() const;
  const std::stringstream &getDoubleOS() const;
  void printValues() const;

 private:
  static const int kInvalidType = 0;
  static const int kCharType = 1;
  static const int kIntType = 2;
  static const int kFloatType = 3;
  static const int kDoubleType = 4;
  static const int kBase = 10;
  static const std::string kCharPrompt;
  static const std::string kIntPrompt;
  static const std::string kFloatPrompt;
  static const std::string kDoublePrompt;
  static const std::string kNonDisplayableMsg;
  static const std::string kImpossibleMsg;

  StringConverter();
  StringConverter(const StringConverter &other);
  StringConverter &operator=(const StringConverter &other);

  bool isChar() const;
  bool isInt() const;
  bool isFloat() const;
  bool isDouble() const;
  void createCharValue();
  void createIntValue();
  void createFloatValue();
  void createDoubleValue();
  void convertChar();
  void convertCharToInt();
  void convertCharToFloat();
  void convertCharToDouble();
  void convertInt();
  void convertIntToChar();
  void convertIntToFloat();
  void convertIntToDouble();
  void convertFloat();
  void convertFloatToChar();
  void convertFloatToInt();
  void convertFloatToDouble();
  void convertDouble();
  void convertDoubleToChar();
  void convertDoubleToInt();
  void convertDoubleToFloat();
  void setAllImpossible();
  char getCharValue() const;
  int getIntValue() const;
  float getFloatValue() const;
  double getDoubleValue() const;

  const std::string &str_;
  int val_type_;
  char char_val_;
  int int_val_;
  float float_val_;
  double double_val_;
  std::stringstream char_ss_;
  std::stringstream int_ss_;
  std::stringstream float_ss_;
  std::stringstream double_ss_;
};

std::ostream &operator<<(std::ostream &os, const StringConverter &s_converter);

#endif // STRINGCONVERTER_HPP
