#include "StringConverter.hpp"

#include <iostream>
#include <sstream>

StringConverter::StringConverter(const std::string &str)
    : str_(str), val_type_(kInvalidType), char_val_(0), int_val_(0),
      float_val_(0), double_val_(0) {
  // std::cout << "StringConverter's default constructor called" << std::endl;
}

StringConverter::~StringConverter() {
  // std::cout << "StringConverter's destructor called" << std::endl;
}

void StringConverter::printValues() const {
  std::cout << "char: '" << char_val_ << "'" << std::endl;
  std::cout << "int: " << int_val_ << std::endl;
  std::cout << "float: " << float_val_ << std::endl;
  std::cout << "double: " << double_val_ << std::endl;
}

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
  // need to implement
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
  // need to implement
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
  if (val_type_ != kCharType) {
    convertToChar();
  }
  if (val_type_ != kIntType) {
    convertToInt();
  }
  if (val_type_ != kFloatType) {
    convertToFloat();
  }
  if (val_type_ != kDoubleType) {
    convertToDouble();
  }
}

void StringConverter::convertToChar() {
  switch (val_type_) {
    case kCharType:
      break;
    case kIntType:
      char_val_ = static_cast<char>(int_val_);
      break;
    case kFloatType:
      char_val_ = static_cast<char>(static_cast<int>(float_val_));
      break;
    case kDoubleType:
      char_val_ = static_cast<char>(static_cast<int>(double_val_));
      break;
    default:
      break;
  }
}

void StringConverter::convertToInt() {
  switch (val_type_) {
    case kCharType:
      // need to implement error handling
      int_val_ = static_cast<int>(char_val_);
      break;
    case kIntType:
      break;
    case kFloatType:
      // need to implement error handling
      int_val_ = static_cast<int>(float_val_);
      break;
    case kDoubleType:
      // need to implement error handling
      int_val_ = static_cast<int>(double_val_);
      break;
    default:
      break;
  }
}

void StringConverter::convertToFloat() {
  switch (val_type_) {
    case kCharType:
      // need to implement error handling
      float_val_ = static_cast<float>(static_cast<int>(char_val_));
      break;
    case kIntType:
      // need to implement error handling
      float_val_ = static_cast<float>(int_val_);
      break;
    case kFloatType:
      break;
    case kDoubleType:
      // need to implement error handling
      float_val_ = static_cast<float>(static_cast<int>(double_val_));
      break;
    default:
      break;
  }
}

void StringConverter::convertToDouble() {
  switch (val_type_) {
    case kCharType:
      // need to implement error handling
      double_val_ = static_cast<double>(static_cast<int>(char_val_));
      break;
    case kIntType:
      // need to implement error handling
      double_val_ = static_cast<double>(int_val_);
      break;
    case kFloatType:
      // need to implement error handling
      double_val_ = static_cast<double>(float_val_);
      break;
    case kDoubleType:
      break;
    default:
      break;
  }
}
