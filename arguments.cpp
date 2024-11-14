#include "arguments.h"

namespace args
{
  const std::string ArgErrText[]
  {
    "Argument error: Argument can\'t be found.",
    "Argument error: Number argument is invalid."
  };

  bool check_flag(std::string_view flag, int flags[])
  {
    if (flag.length() == 1)
    {
      if (passgen::numbers.find(flag) != std::string::npos && flag[0] != '0')
      {
        flags[NUMBER] = std::stoi(std::string(flag));
        return true;
      }
      std::cerr << ArgErrText[ARGUMENT_NUMBER_INVALID] << '\n';
      return false;
    }

    if (flag[0] == '-')
    {
      for (int i = 1; i < flag.length(); ++i)
      {
        switch (flag[i]) 
        {
          case 'u':
            flags[UPPERCASE] = 1;
            break;
          case 'l':
            flags[LOWERCASE] = 1;
            break;
          case 'n':
            flags[DIGIT] = 1;
            break;
          case 's':
            flags[SYMBOL] = 1;
            break;
          default:
            std::cerr << ArgErrText[ARGUMENT_NOT_FOUND] << '\n';
            return false;
        }
      }
      return true;
    }

    for (int i = 0; i < flag.length(); ++i)
    {
      if (passgen::numbers.find(flag[i]) == std::string::npos) 
      {
        std::cerr << ArgErrText[ARGUMENT_NUMBER_INVALID] << '\n';
        return false;
      }
    }
    
    flags[NUMBER] = std::stoi(std::string(flag));

    return true;
  }
};

