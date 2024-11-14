#ifndef ARGUMENTS_H
#define ARGUMENTS_H


#include "passgen.h"
#include <iostream>

namespace args
{
  enum flag_codes
  {
    UPPERCASE,
    LOWERCASE,
    DIGIT,
    SYMBOL,
    NUMBER
  };

  enum ArgErr
  {
    ARGUMENT_NOT_FOUND,
    ARGUMENT_NUMBER_INVALID,
  };

  bool check_flag(std::string_view flag, int flags[]);
};

#endif
