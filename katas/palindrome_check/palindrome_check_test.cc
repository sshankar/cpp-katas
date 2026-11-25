#include "katas/palindrome_check/palindrome_check.h"

#include <gtest/gtest.h>

namespace kata::palindrome_check {
namespace {

TEST(PalindromeCheckTest, EmptyAndSingle) {
  EXPECT_TRUE(IsPalindrome(""));
  EXPECT_TRUE(IsPalindrome("a"));
}

TEST(PalindromeCheckTest, SimpleWords) {
  EXPECT_TRUE(IsPalindrome("racecar"));
  EXPECT_TRUE(IsPalindrome("abba"));
  EXPECT_FALSE(IsPalindrome("hello"));
  EXPECT_FALSE(IsPalindrome("ab"));
}

TEST(PalindromeCheckTest, IgnoresCaseAndPunctuation) {
  EXPECT_TRUE(IsPalindrome("A man, a plan, a canal: Panama"));
  EXPECT_TRUE(IsPalindrome("No 'x' in Nixon"));
  EXPECT_FALSE(IsPalindrome("race a car"));
}

TEST(PalindromeCheckTest, DigitsCount) {
  EXPECT_TRUE(IsPalindrome("12321"));
  EXPECT_FALSE(IsPalindrome("0P"));
}

TEST(PalindromeCheckTest, OnlyPunctuation) { EXPECT_TRUE(IsPalindrome(" .,!")); }

}  // namespace
}  // namespace kata::palindrome_check
