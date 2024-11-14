#ifndef PASSGEN_H
#define PASSGEN_H

#include <string>
#include <string_view>

namespace passgen
{
  inline constexpr std::string_view abc_lowercase { "abcdefghijklmnopqrstuvwxyz" };
  inline constexpr std::string_view abc_uppercase { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
  inline constexpr std::string_view numbers       { "1234567890" };
  inline constexpr std::string_view specials      { "!#$%&()*+,-./:;=?@^_" };

  std::string generate_password(int flags[]);
};

#endif
