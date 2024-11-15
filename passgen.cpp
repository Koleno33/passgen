#include "arguments.h"
#include "passgen.h"

namespace passgen
{
  std::string generate_password(int flags[])
  {
    std::string res { "" };

    bool uppercase { static_cast<bool>(flags[0]) };
    bool lowercase { static_cast<bool>(flags[1]) };
    bool digits    { static_cast<bool>(flags[2]) };
    bool symbols   { static_cast<bool>(flags[3]) };
    int N          { flags[4] };

    if (!uppercase && !lowercase && !digits && !symbols)
    {
      uppercase = true;
      lowercase = true;
      digits = true;
      symbols = true;
    }

    if (N == 0) N = 8 + rand() % 5;

    for (int i = 0; i < N; ++i)
    {
      while (true)
      {
        int choice = rand() % 4;
        if (uppercase && choice == args::UPPERCASE)
        {
          res += abc_uppercase[rand() % abc_uppercase.length()];
          break;
        }
        else if (lowercase && choice == args::LOWERCASE)
        {
          res += abc_lowercase[rand() % abc_lowercase.length()];
          break;
        }
        else if (digits && choice == args::DIGIT)
        {
          res += numbers[rand() % numbers.length()];
          break;
        }
        else if (symbols && choice == args::SYMBOL)
        {
          res += specials[rand() % specials.length()];
          break;
        }
      }
    }

    return res;
  }
};

int main(int argc, char* argv[])
{
  srand(time(NULL));
  if (argc >= 1)
  {
    int flags[] { 0, 0, 0, 0, 0 };

    for (int i = 1; i < argc; ++i)
    {
      std::string_view flag { argv[i] };
      if (!args::check_flag(flag, flags))
      {
        return 1;
      }
    }
    std::cout << passgen::generate_password(flags) << '\n';
  }
  return 0;
}
