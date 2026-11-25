#include "katas/palindrome_check/palindrome_check.h"

#include <cctype>
#include <cstddef>

namespace kata::palindrome_check {

namespace {

// <cctype> functions require values representable as unsigned char.
bool IsAlnum(char c) { return std::isalnum(static_cast<unsigned char>(c)); }
int Lower(char c) { return std::tolower(static_cast<unsigned char>(c)); }

}  // namespace

bool IsPalindrome(std::string_view s) {
  if (s.empty()) return true;
  std::size_t i = 0, j = s.size() - 1;
  while (i < j) {
    if (!IsAlnum(s[i])) {
      ++i;
    } else if (!IsAlnum(s[j])) {
      --j;
    } else {
      if (Lower(s[i]) != Lower(s[j])) return false;
      ++i;
      --j;
    }
  }
  return true;
}

}  // namespace kata::palindrome_check
