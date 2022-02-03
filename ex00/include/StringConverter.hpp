#ifndef STRINGCONVERTER_HPP
#define STRINGCONVERTER_HPP

#include <string>

class StringConverter {
 public:
  StringConverter(const std::string &str);
  virtual ~StringConverter();

  void setValueType();
  void createBaseValue();
  void convertToOtherTypes();
  void printValues() const;

 private:
  static const int kInvalidType = 0;
  static const int kCharType = 1;
  static const int kIntType = 2;
  static const int kFloatType = 3;
  static const int kDoubleType = 4;

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
  void convertToChar();
  void convertToInt();
  void convertToFloat();
  void convertToDouble();
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
};

#endif // STRINGCONVERTER_HPP
