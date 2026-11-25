#include "katas/bitwise_addition/bitwise_addition.h"

#include <gtest/gtest.h>

#include <climits>

namespace kata::bitwise_addition {
namespace {

TEST(BitwiseAdditionTest, Positives) {
  EXPECT_EQ(Add(2, 3), 5);
  EXPECT_EQ(Add(1000000, 234567), 1234567);
}

TEST(BitwiseAdditionTest, Zero) {
  EXPECT_EQ(Add(0, 0), 0);
  EXPECT_EQ(Add(0, 9), 9);
  EXPECT_EQ(Add(-9, 0), -9);
}

TEST(BitwiseAdditionTest, MixedSigns) {
  EXPECT_EQ(Add(-5, 3), -2);
  EXPECT_EQ(Add(5, -3), 2);
  EXPECT_EQ(Add(7, -7), 0);
}

TEST(BitwiseAdditionTest, Negatives) { EXPECT_EQ(Add(-4, -6), -10); }

TEST(BitwiseAdditionTest, Extremes) {
  EXPECT_EQ(Add(INT_MAX, INT_MIN), -1);
  EXPECT_EQ(Add(INT_MAX, 1), INT_MIN);  // Wraps.
}

}  // namespace
}  // namespace kata::bitwise_addition
