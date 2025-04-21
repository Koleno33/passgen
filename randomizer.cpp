#include <random>

namespace randomizer
{
  struct PRNG
  {
      std::mt19937 engine;
  };

  void initGenerator(PRNG& generator)
  {
      std::random_device device;

      generator.engine.seed(device());
  }

  unsigned random(PRNG& generator, unsigned minValue, unsigned maxValue)
  {
      std::uniform_int_distribution<unsigned> distribution(minValue, maxValue);

      return distribution(generator.engine);
  }
};

