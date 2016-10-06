#include "random_helper.hpp"

int randint(int minval, int maxval) {
  return std::uniform_int_distribution<int>{minval, maxval}(ENGINE);
}

int randint(int maxval) {
  return randint(0, maxval);
}
