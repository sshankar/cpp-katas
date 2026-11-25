#include "katas/bitwise_division/bitwise_division.h"

#include <gtest/gtest.h>

#include <climits>

namespace kata::bitwise_division {
namespace {

TEST(BitwiseDivisionTest, Exact) {
  EXPECT_EQ(Divide(100, 10), 10);
  EXPECT_EQ(Divide(7, 7), 1);
}

TEST(BitwiseDivisionTest, Truncates) {
  EXPECT_EQ(Divide(10, 3), 3);
  EXPECT_EQ(Divide(1, 2), 0);
}

TEST(BitwiseDivisionTest, TruncatesTowardZeroForNegatives) {
  EXPECT_EQ(Divide(7, -3), -2);
  EXPECT_EQ(Divide(-7, 2), -3);
  EXPECT_EQ(Divide(-7, -2), 3);
}

TEST(BitwiseDivisionTest, ZeroDividend) { EXPECT_EQ(Divide(0, 5), 0); }

TEST(BitwiseDivisionTest, Extremes) {
  EXPECT_EQ(Divide(INT_MAX, 1), INT_MAX);
  EXPECT_EQ(Divide(INT_MIN, 1), INT_MIN);
  EXPECT_EQ(Divide(INT_MIN, 2), INT_MIN / 2);
  EXPECT_EQ(Divide(INT_MIN, INT_MIN), 1);
  EXPECT_EQ(Divide(INT_MAX, INT_MIN), 0);
}

TEST(BitwiseDivisionTest, OverflowClampsToIntMax) {
  EXPECT_EQ(Divide(INT_MIN, -1), INT_MAX);
}

}  // namespace
}  // namespace kata::bitwise_division
