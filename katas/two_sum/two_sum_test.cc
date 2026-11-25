#include "katas/two_sum/two_sum.h"

#include <gtest/gtest.h>

#include <climits>
#include <utility>

namespace kata::two_sum {
namespace {

using Indices = std::pair<std::size_t, std::size_t>;

TEST(TwoSumTest, FirstTwo) {
  EXPECT_EQ(TwoSum({2, 7, 11, 15}, 9), Indices(0, 1));
}

TEST(TwoSumTest, NotAdjacentToStart) {
  EXPECT_EQ(TwoSum({3, 2, 4}, 6), Indices(1, 2));
}

TEST(TwoSumTest, DuplicateValues) {
  EXPECT_EQ(TwoSum({3, 3}, 6), Indices(0, 1));
}

TEST(TwoSumTest, NegativesAndZeroTarget) {
  EXPECT_EQ(TwoSum({-3, 4, 3, 90}, 0), Indices(0, 2));
}

TEST(TwoSumTest, NoPair) {
  EXPECT_EQ(TwoSum({1, 2, 3}, 7), std::nullopt);
  EXPECT_EQ(TwoSum({}, 0), std::nullopt);
  EXPECT_EQ(TwoSum({5}, 10), std::nullopt);  // An element can't pair with itself.
}

TEST(TwoSumTest, NoOverflow) {
  EXPECT_EQ(TwoSum({INT_MAX, -1, INT_MIN}, -1), Indices(0, 2));
  EXPECT_EQ(TwoSum({INT_MAX, 1}, INT_MIN), std::nullopt);
}

}  // namespace
}  // namespace kata::two_sum
