#include "katas/bitwise_power_of_two/bitwise_power_of_two.h"

#include <gtest/gtest.h>

#include <cstdint>
#include <limits>

namespace kata::bitwise_power_of_two {
namespace {

TEST(BitwisePowerOfTwoTest, ZeroIsNot) { EXPECT_FALSE(IsPowerOfTwo(0)); }

TEST(BitwisePowerOfTwoTest, EveryPowerOfTwo) {
  for (int i = 0; i < 64; ++i) {
    EXPECT_TRUE(IsPowerOfTwo(std::uint64_t{1} << i)) << "2^" << i;
  }
}

TEST(BitwisePowerOfTwoTest, NonPowers) {
  for (std::uint64_t n : {3, 5, 6, 7, 12, 1023, 1025}) {
    EXPECT_FALSE(IsPowerOfTwo(n)) << n;
  }
  EXPECT_FALSE(IsPowerOfTwo(std::numeric_limits<std::uint64_t>::max()));
}

}  // namespace
}  // namespace kata::bitwise_power_of_two
