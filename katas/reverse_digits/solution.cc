#include "katas/reverse_digits/reverse_digits.h"

#include <climits>

namespace kata::reverse_digits {

// In C++, n % 10 keeps the sign of n, so negatives need no special casing.
int ReverseDigits(int n) {
  long long reversed = 0;
  while (n != 0) {
    reversed = reversed * 10 + n % 10;
    n /= 10;
    if (reversed > INT_MAX || reversed < INT_MIN) return 0;
  }
  return static_cast<int>(reversed);
}

}  // namespace kata::reverse_digits
