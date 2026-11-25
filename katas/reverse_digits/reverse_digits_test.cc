#include "katas/reverse_digits/reverse_digits.h"

#include <gtest/gtest.h>

#include <climits>

namespace kata::reverse_digits {
namespace {

TEST(ReverseDigitsTest, Positive) {
  EXPECT_EQ(ReverseDigits(123), 321);
  EXPECT_EQ(ReverseDigits(7), 7);
}

TEST(ReverseDigitsTest, Negative) { EXPECT_EQ(ReverseDigits(-456), -654); }

TEST(ReverseDigitsTest, TrailingZerosDrop) {
  EXPECT_EQ(ReverseDigits(120), 21);
  EXPECT_EQ(ReverseDigits(-450), -54);
}

TEST(ReverseDigitsTest, Zero) { EXPECT_EQ(ReverseDigits(0), 0); }

TEST(ReverseDigitsTest, LargestThatFits) {
  EXPECT_EQ(ReverseDigits(1463847412), 2147483641);
  EXPECT_EQ(ReverseDigits(-1463847412), -2147483641);
}

TEST(ReverseDigitsTest, OverflowReturnsZero) {
  EXPECT_EQ(ReverseDigits(1534236469), 0);
  EXPECT_EQ(ReverseDigits(INT_MAX), 0);
  EXPECT_EQ(ReverseDigits(INT_MIN), 0);
}

}  // namespace
}  // namespace kata::reverse_digits
