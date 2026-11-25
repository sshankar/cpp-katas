#ifndef KATAS_PALINDROME_CHECK_PALINDROME_CHECK_H_
#define KATAS_PALINDROME_CHECK_PALINDROME_CHECK_H_

#include <string_view>

namespace kata::palindrome_check {

// Returns true if s reads the same forwards and backwards, considering only
// ASCII letters and digits and ignoring case. Use O(1) extra space.
// "A man, a plan, a canal: Panama" is a palindrome.
bool IsPalindrome(std::string_view s);

}  // namespace kata::palindrome_check

#endif  // KATAS_PALINDROME_CHECK_PALINDROME_CHECK_H_
