#ifndef STRINGCONVERTER_HPP
#define STRINGCONVERTER_HPP

#include <math.h>

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cerrno>

class StringConverter {
 public:
  StringConverter(const std::string &str);
  virtual ~StringConverter();

  void setValueType();
  void createBaseValue();
  void convertToOtherTypes();
  void setStringStreams();
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
  static const std::string kDecimalPoint;
  static const std::string kExponent;

  StringConverter();
  StringConverter(const StringConverter &other);
  StringConverter &operator=(const StringConverter &other);

  bool isChar();
  bool isInt();
  bool isFloat();
  bool isDouble();
  bool isinff();
  bool isnanf();
  void setCharSS();
  void setIntSS();
  void setFloatSS();
  void setDoubleSS();

  const std::string &str_;
  long strtol_val_;
  char* strtol_end_;
  double strtod_val_;
  char* strtod_end_;
  int val_type_;
  char char_val_;
  int int_val_;
  float float_val_;
  double double_val_;
  std::stringstream char_ss_;
  std::stringstream int_ss_;
  std::stringstream float_ss_;
  std::stringstream double_ss_;
  bool is_out_of_range_char;
  bool is_out_of_range_int;
  bool is_out_of_range_float;
  bool is_invalid_input;
};

std::ostream &operator<<(std::ostream &os, const StringConverter &s_converter);

#endif // STRINGCONVERTER_HPP
