#include "katas/bitwise_non_duplicate/bitwise_non_duplicate.h"

#include <gtest/gtest.h>

#include <climits>

namespace kata::bitwise_non_duplicate {
namespace {

TEST(BitwiseNonDuplicateTest, SingleElement) {
  EXPECT_EQ(FindNonDuplicate({7}), 7);
}

TEST(BitwiseNonDuplicateTest, UniqueInMiddle) {
  EXPECT_EQ(FindNonDuplicate({1, 2, 1}), 2);
}

TEST(BitwiseNonDuplicateTest, UnorderedWithNegatives) {
  EXPECT_EQ(FindNonDuplicate({4, -1, 2, -1, 2}), 4);
  EXPECT_EQ(FindNonDuplicate({3, -8, 3}), -8);
}

TEST(BitwiseNonDuplicateTest, Extremes) {
  EXPECT_EQ(FindNonDuplicate({INT_MAX, INT_MIN, INT_MAX}), INT_MIN);
}

}  // namespace
}  // namespace kata::bitwise_non_duplicate
