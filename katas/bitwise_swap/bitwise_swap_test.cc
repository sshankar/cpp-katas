#include "katas/bitwise_swap/bitwise_swap.h"

#include <gtest/gtest.h>

#include <climits>

namespace kata::bitwise_swap {
namespace {

TEST(BitwiseSwapTest, SwapsPositives) {
  int a = 3, b = 7;
  Swap(a, b);
  EXPECT_EQ(a, 7);
  EXPECT_EQ(b, 3);
}

TEST(BitwiseSwapTest, SwapsNegativesAndExtremes) {
  int a = INT_MIN, b = -1;
  Swap(a, b);
  EXPECT_EQ(a, -1);
  EXPECT_EQ(b, INT_MIN);
}

TEST(BitwiseSwapTest, EqualValues) {
  int a = 5, b = 5;
  Swap(a, b);
  EXPECT_EQ(a, 5);
  EXPECT_EQ(b, 5);
}

TEST(BitwiseSwapTest, SameObjectIsUnchanged) {
  int a = 42;
  Swap(a, a);
  EXPECT_EQ(a, 42);
}

}  // namespace
}  // namespace kata::bitwise_swap
