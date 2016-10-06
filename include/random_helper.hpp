#ifndef INCLUDE_RANDOM_HELPER_HPP_
#define INCLUDE_RANDOM_HELPER_HPP_

#include <random>

static std::random_device TRUERAND;
static std::default_random_engine ENGINE{TRUERAND()};

int randint(int minval, int maxval);
int randint(int maxval);
#endif  // INCLUDE_RANDOM_HELPER_HPP_
