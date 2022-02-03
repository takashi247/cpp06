#ifndef STRINGCONVERTER_HPP
#define STRINGCONVERTER_HPP

#include <string>

class StringConverter {
 public:
  StringConverter(const std::string &str);
  virtual ~StringConverter();

  char getCharValue() const;
  int getIntValue() const;
  float getFloatValue() const;
  double getDoubleValue() const;

 private:
  static const int kCharIndex = 0;
  static const int kIntIndex = 1;
  static const int kFloatIndex = 2;
  static const int kDoubleIndex = 3;

  StringConverter();
  StringConverter(const StringConverter &other);
  StringConverter &operator=(const StringConverter &other);

  int judgeType(const std::string &str);
  void createBaseValue(const std::string &str);
  void convertToOtherTypes();

  int type_;
  char char_value_;
  int int_value_;
  float float_value_;
  double double_value_;
};

#endif // STRINGCONVERTER_HPP
