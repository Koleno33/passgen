#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>

namespace randomizer
{
  struct PRNG
  {
      std::mt19937 engine;
  };

  void initGenerator(PRNG& generator);

  unsigned random(PRNG& generator, unsigned minValue, unsigned maxValue);
};

#endif
