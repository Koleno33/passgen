#include "arguments.h"
#include "passgen.h"
#include "randomizer.h"

namespace passgen
{
  std::string generate_password(int flags[], randomizer::PRNG& generator)
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
        int choice = randomizer::random(generator, 0, 3);
        int second_choice {};
        if (uppercase && choice == args::UPPERCASE)
        {
          second_choice = randomizer::random(generator, 0, abc_uppercase.length() - 1);
          res += abc_uppercase[second_choice];
          break;
        }
        else if (lowercase && choice == args::LOWERCASE)
        {
          second_choice = randomizer::random(generator, 0, abc_lowercase.length() - 1);
          res += abc_lowercase[second_choice];
          break;
        }
        else if (digits && choice == args::DIGIT)
        {
          second_choice = randomizer::random(generator, 0, numbers.length() - 1);
          res += numbers[second_choice];
          break;
        }
        else if (symbols && choice == args::SYMBOL)
        {
          second_choice = randomizer::random(generator, 0, specials.length() - 1);
          res += specials[second_choice];
          break;
        }
      }
    }

    return res;
  }
};

int main(int argc, char* argv[])
{
  randomizer::PRNG generator{};
  randomizer::initGenerator(generator);

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
    std::cout << passgen::generate_password(flags, generator) << '\n';
  }
  return 0;
}
