#include "StringConverter.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

const std::string StringConverter::kCharPrompt = "char: ";
const std::string StringConverter::kIntPrompt = "int: ";
const std::string StringConverter::kFloatPrompt = "float: ";
const std::string StringConverter::kDoublePrompt = "double: ";
const std::string StringConverter::kNonDisplayableMsg = "Non displayable";

StringConverter::StringConverter(const std::string &str)
    : str_(str), val_type_(kInvalidType), char_val_(), int_val_(),
      float_val_(), double_val_(), char_ss_(), int_ss_(),
      float_ss_(), double_ss_() {
  char_ss_ << kCharPrompt;
  int_ss_ << kIntPrompt;
  float_ss_ << kFloatPrompt;
  double_ss_ << kDoublePrompt;
}

StringConverter::~StringConverter() {}

const std::stringstream &StringConverter::getCharOS() const { return char_ss_; }

const std::stringstream &StringConverter::getIntOS() const { return int_ss_; }

const std::stringstream &StringConverter::getFloatOS() const { return float_ss_; }

const std::stringstream &StringConverter::getDoubleOS() const { return double_ss_; }

void StringConverter::setValueType() {
  if (isChar()) {
    val_type_ = kCharType;
  } else if (isInt()) {
    val_type_ = kIntType;
  } else if (isFloat()) {
    val_type_ = kFloatType;
  } else if (isDouble()) {
    val_type_ = kDoubleType;
  }
}

bool StringConverter::isChar() const {
  // if the given string is NULL
  if (str_.length() == 0) {
    return true;
  }
  // len == 1 and NOT a digit
  if (str_.length() == 1 && !std::isdigit(str_[0])) {
    return true;
  }
  return false;
}

bool StringConverter::isInt() const {
  // need to implement
  return true;
}

bool StringConverter::isFloat() const {
  // need to implement
  return false;
}

bool StringConverter::isDouble() const {
  // need to implement
  return false;
}

void StringConverter::createBaseValue() {
  switch (val_type_) {
    case kCharType:
      createCharValue();
      break;
    case kIntType:
      createIntValue();
      break;
    case kFloatType:
      createFloatValue();
      break;
    case kDoubleType:
      createDoubleValue();
      break;
    default:
      break;
  }
}

void StringConverter::createCharValue() {
  char_val_ = static_cast<char>(str_[0]);
  if (std::isprint(str_[0])) {
    char_ss_ <<"'" << char_val_ << "'";
  } else {
    char_ss_ << kNonDisplayableMsg;
  }
  return ;
}

void StringConverter::createIntValue() {
  // need to add error handling
  std::istringstream iss(str_);
  iss >> int_val_;
}

void StringConverter::createFloatValue() {
  // need to implement
  return ;
}

void StringConverter::createDoubleValue() {
  // need to implement
  return ;
}

void StringConverter::convertToOtherTypes() {
  switch (val_type_) {
    case kCharType:
      convertChar();
      break;
    case kIntType:
      convertInt();
      break;
    case kFloatType:
      convertFloat();
      break;
    case kDoubleType:
      convertDouble();
      break;
    default:
      break;
  }
}

void StringConverter::convertChar() {
  convertCharToInt();
  convertCharToFloat();
  convertCharToDouble();
}

void StringConverter::convertCharToInt() {
  int_val_ = static_cast<int>(char_val_);
  int_ss_ << int_val_;
}

void StringConverter::convertCharToFloat() {
  float_val_ = static_cast<float>(char_val_);
  float_ss_ << float_val_ << ".0f";
}

void StringConverter::convertCharToDouble() {
  double_val_ = static_cast<double>(char_val_);
  double_ss_ << double_val_ << ".0";
}

void StringConverter::convertInt() {
  convertIntToChar();
  convertIntToFloat();
  convertIntToDouble();
}

void StringConverter::convertIntToChar() {
  // need to implement
}

void StringConverter::convertIntToFloat() {
  // need to implement
}

void StringConverter::convertIntToDouble() {
  // need to implement
}

void StringConverter::convertFloat() {
  convertFloatToChar();
  convertFloatToInt();
  convertFloatToDouble();
}

void StringConverter::convertFloatToChar() {
  // need to implement
}

void StringConverter::convertFloatToInt() {
  // need to implement
}

void StringConverter::convertFloatToDouble() {
  // need to implement
}

void StringConverter::convertDouble() {
  convertDoubleToChar();
  convertDoubleToInt();
  convertDoubleToFloat();
}

void StringConverter::convertDoubleToChar() {
  // need to implement
}

void StringConverter::convertDoubleToInt() {
  // need to implement
}

void StringConverter::convertDoubleToFloat() {
  // need to implement
}

std::ostream &operator<<(std::ostream &os, const StringConverter &s_converter) {
  os << s_converter.getCharOS().str() << "\n";
  os << s_converter.getIntOS().str() << "\n";
  os << s_converter.getFloatOS().str() << "\n";
  os << s_converter.getDoubleOS().str();
  return os;
}
