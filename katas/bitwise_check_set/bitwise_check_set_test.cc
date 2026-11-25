#include "katas/bitwise_check_set/bitwise_check_set.h"

#include <gtest/gtest.h>

namespace kata::bitwise_check_set {
namespace {

TEST(BitwiseCheckSetTest, LowBits) {
  EXPECT_FALSE(IsBitSet(0b1010, 0));
  EXPECT_TRUE(IsBitSet(0b1010, 1));
  EXPECT_FALSE(IsBitSet(0b1010, 2));
  EXPECT_TRUE(IsBitSet(0b1010, 3));
}

TEST(BitwiseCheckSetTest, HighestBit) {
  EXPECT_TRUE(IsBitSet(0x80000000u, 31));
  EXPECT_FALSE(IsBitSet(0x7FFFFFFFu, 31));
}

TEST(BitwiseCheckSetTest, Zero) {
  for (int bit = 0; bit < 32; ++bit) EXPECT_FALSE(IsBitSet(0, bit)) << bit;
}

TEST(BitwiseCheckSetTest, AllOnes) {
  for (int bit = 0; bit < 32; ++bit) EXPECT_TRUE(IsBitSet(~0u, bit)) << bit;
}

}  // namespace
}  // namespace kata::bitwise_check_set
