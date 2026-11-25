#include "katas/exponent/exponent.h"

#include <gtest/gtest.h>

#include <climits>

namespace kata::exponent {
namespace {

TEST(ExponentTest, ZeroExponent) {
  EXPECT_DOUBLE_EQ(Power(5.0, 0), 1.0);
  EXPECT_DOUBLE_EQ(Power(0.0, 0), 1.0);
}

TEST(ExponentTest, PositiveExponent) {
  EXPECT_DOUBLE_EQ(Power(2.0, 10), 1024.0);
  EXPECT_DOUBLE_EQ(Power(3.0, 5), 243.0);
  EXPECT_DOUBLE_EQ(Power(1.5, 2), 2.25);
}

TEST(ExponentTest, NegativeBase) {
  EXPECT_DOUBLE_EQ(Power(-3.0, 3), -27.0);
  EXPECT_DOUBLE_EQ(Power(-2.0, 4), 16.0);
}

TEST(ExponentTest, NegativeExponent) {
  EXPECT_DOUBLE_EQ(Power(2.0, -2), 0.25);
  EXPECT_DOUBLE_EQ(Power(-2.0, -3), -0.125);
}

TEST(ExponentTest, ExtremeExponents) {
  EXPECT_DOUBLE_EQ(Power(1.0, INT_MIN), 1.0);
  EXPECT_DOUBLE_EQ(Power(-1.0, INT_MAX), -1.0);
  EXPECT_DOUBLE_EQ(Power(2.0, 62), 4611686018427387904.0);
}

}  // namespace
}  // namespace kata::exponent
