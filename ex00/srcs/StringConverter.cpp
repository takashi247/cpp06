#include "StringConverter.hpp"

const std::string StringConverter::kCharPrompt = "char: ";
const std::string StringConverter::kIntPrompt = "int: ";
const std::string StringConverter::kFloatPrompt = "float: ";
const std::string StringConverter::kDoublePrompt = "double: ";
const std::string StringConverter::kNonDisplayableMsg = "Non displayable";
const std::string StringConverter::kImpossibleMsg = "impossible";
const std::string StringConverter::kDecimalPoint = ".";
const std::string StringConverter::kExponent="e";

StringConverter::StringConverter(const std::string &str)
    : str_(str), strtol_val_(), strtol_end_(NULL), strtod_val_(),
      strtod_end_(NULL), val_type_(), char_val_(), int_val_(),
      float_val_(), double_val_(), char_ss_(), int_ss_(), float_ss_(),
      double_ss_(), is_out_of_range_char(false), is_out_of_range_int(false),
      is_out_of_range_float(false), is_invalid_input(false) {
  strtod_val_ = std::strtod(str_.c_str(), &strtod_end_);
  if (errno == ERANGE && strtod_val_ == HUGE_VAL) {
    is_invalid_input = true;
    errno = 0;
  }
  strtol_val_ = std::strtol(str_.c_str(), &strtol_end_, kBase);
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
  if (is_invalid_input) {
    val_type_ = kInvalidType;
  } else if (isChar()) {
    val_type_ = kCharType;
  } else if (isInt()) {
    val_type_ = kIntType;
  } else if (isFloat()) {
    val_type_ = kFloatType;
  } else if (isDouble()) {
    val_type_ = kDoubleType;
  } else {
    val_type_ = kInvalidType;
    is_invalid_input = true;
  }
}

bool StringConverter::isChar() {
  if ((str_.length() == 0) || (str_.length() == 1 && !std::isdigit(str_[0]))) {
    return true;
  } else {
    long lcasted_char_min = static_cast<long>(std::numeric_limits<char>::min());
    long lcasted_char_max = static_cast<long>(std::numeric_limits<char>::max());
    double dcasted_char_min = static_cast<double>(std::numeric_limits<char>::min());
    double dcasted_char_max = static_cast<double>(std::numeric_limits<char>::max());
    if (strtol_val_ < lcasted_char_min || lcasted_char_max < strtol_val_
        || strtod_val_ < dcasted_char_min || dcasted_char_max < strtod_val_
        || isnan(strtod_val_) || isinf(strtod_val_)) {
      is_out_of_range_char = true;
    }
    return false;
  }
}

bool StringConverter::isInt() {
  long lcasted_int_min = static_cast<long>(std::numeric_limits<int>::min());
  long lcasted_int_max = static_cast<long>(std::numeric_limits<int>::max());
  double dcasted_int_min = static_cast<double>(std::numeric_limits<int>::min());
  double dcasted_int_max = static_cast<double>(std::numeric_limits<int>::max());
  if (strtol_val_ < lcasted_int_min || lcasted_int_max < strtol_val_
      || strtod_val_ < dcasted_int_min || dcasted_int_max < strtod_val_
      || isnan(strtod_val_) || isinf(strtod_val_)) {
    is_out_of_range_int = true;
    return false;
  } else if (*strtol_end_) {
    return false;
  } else {
    return true;
  }
}

bool StringConverter::isinff() {
  return (isinf(strtod_val_) && *strtod_end_
          && (*strtod_end_ == 'f' || *strtod_end_ == 'F')
          && !*(strtod_end_ + 1));
}

bool StringConverter::isnanf() {
  return (isnan(strtod_val_) && *strtod_end_
          && (*strtod_end_ == 'f' || *strtod_end_ == 'F')
          && !*(strtod_end_ + 1));
}

bool StringConverter::isFloat() {
  double strtod_abs_val = fabs(strtod_val_);
  float fcasted_strtod_abs_val = static_cast<float>(strtod_abs_val);
  double dcasted_float_max = static_cast<double>(std::numeric_limits<float>::max());
  if ((isinf(fcasted_strtod_abs_val) && !isinf(strtod_abs_val))
      || (isnan(fcasted_strtod_abs_val) && !isnan(strtod_abs_val))
      || (!isinf(strtod_abs_val) && !isnan(strtod_abs_val) && dcasted_float_max < strtod_abs_val)) {
    is_out_of_range_float = true;
    return false;
  } else if (*strtod_end_ != 'f' && *strtod_end_ != 'F') {
    return false;
  } else if (isinff() || isnanf() || ((*strtod_end_ == 'f' || *strtod_end_ == 'F') && !*(strtod_end_ + 1))) {
    return true;
  } else {
    return false;
  }
}

bool StringConverter::isDouble() {
  if (!*strtod_end_ || *strtod_end_ == 'e' || *strtod_end_ == 'E') {
    return true;
  } else {
    return false;
  }
}

void StringConverter::createBaseValue() {
  switch (val_type_) {
    case kCharType:
      char_val_ = str_.c_str()[0];
      break;
    case kIntType:
      int_val_ = std::atoi(str_.c_str());
      break;
    case kFloatType:
      float_val_ = static_cast<float>(strtod_val_);
      break;
    case kDoubleType:
      double_val_ = strtod_val_;
      break;
    default:
      break;
  }
}

void StringConverter::convertToOtherTypes() {
  switch (val_type_) {
    case kCharType:
      int_val_ = static_cast<int>(char_val_);
      float_val_ = static_cast<float>(char_val_);
      double_val_ = static_cast<double>(char_val_);
      break;
    case kIntType:
      char_val_ = static_cast<char>(int_val_);
      float_val_ = static_cast<float>(int_val_);
      double_val_ = static_cast<double>(int_val_);
      break;
    case kFloatType:
      char_val_ = static_cast<char>(float_val_);
      int_val_ = static_cast<int>(float_val_);
      double_val_ = static_cast<double>(float_val_);
      break;
    case kDoubleType:
      char_val_ = static_cast<char>(double_val_);
      int_val_ = static_cast<int>(double_val_);
      float_val_ = static_cast<float>(double_val_);
      break;
    default:
      break;
  }
}

void StringConverter::setStringStreams() {
  setCharSS();
  setIntSS();
  setFloatSS();
  setDoubleSS();
}

void StringConverter::setCharSS() {
  if (is_invalid_input || is_out_of_range_char) {
    char_ss_ << kImpossibleMsg;
  } else {
    if (std::isprint(static_cast<unsigned char>(char_val_))) {
      char_ss_ << "'" << char_val_ << "'";
    } else {
      char_ss_ << kNonDisplayableMsg;
    }
  }
}

void StringConverter::setIntSS() {
  if (is_invalid_input || is_out_of_range_int) {
    int_ss_ << kImpossibleMsg;
  } else {
    int_ss_ << int_val_;
  }
}

void StringConverter::setFloatSS() {
  if (is_invalid_input || is_out_of_range_float) {
    float_ss_ << kImpossibleMsg;
  } else {
    float_ss_ << float_val_;
    std::string str_float_val_ = float_ss_.str();
    if (str_float_val_.find(kDecimalPoint, kFloatPrompt.length()) == std::string::npos
        && str_float_val_.find(kExponent, kFloatPrompt.length()) == std::string::npos
        && !isnan(float_val_) && !isinf(float_val_)) {
      float_ss_ << ".0f";
    } else {
      float_ss_ << "f";
    }
  }
}

void StringConverter::setDoubleSS() {
  if (is_invalid_input) {
    double_ss_ << kImpossibleMsg;
  } else {
    double_ss_ << double_val_;
    std::string str_double_val_ = double_ss_.str();
    if (str_double_val_.find(kDecimalPoint, kDoublePrompt.length()) == std::string::npos
        && str_double_val_.find(kExponent, kDoublePrompt.length()) == std::string::npos
        && !isnan(double_val_) && !isinf(double_val_)) {
      double_ss_ << ".0";
    }
  }
}

std::ostream &operator<<(std::ostream &os, const StringConverter &s_converter) {
  os << s_converter.getCharOS().str() << "\n";
  os << s_converter.getIntOS().str() << "\n";
  os << s_converter.getFloatOS().str() << "\n";
  os << s_converter.getDoubleOS().str();
  return os;
}
