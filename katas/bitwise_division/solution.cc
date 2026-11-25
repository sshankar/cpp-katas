#include "katas/bitwise_division/bitwise_division.h"

#include <climits>
#include <cstdint>

namespace kata::bitwise_division {

namespace {

// |x| as unsigned; works for INT_MIN, whose magnitude doesn't fit in int.
std::uint32_t Magnitude(int x) {
  auto u = static_cast<std::uint32_t>(x);
  return x < 0 ? 0u - u : u;
}

}  // namespace

// Long division in base 2: from the highest bit down, subtract divisor << i
// whenever it fits, and set bit i of the quotient.
int Divide(int dividend, int divisor) {
  if (dividend == INT_MIN && divisor == -1) return INT_MAX;

  const bool negative = (dividend < 0) != (divisor < 0);
  std::uint32_t remaining = Magnitude(dividend);
  const std::uint32_t d = Magnitude(divisor);

  std::uint32_t quotient = 0;
  for (int i = 31; i >= 0; --i) {
    if ((remaining >> i) >= d) {  // Comparing shifted-down avoids overflow.
      remaining -= d << i;
      quotient |= 1u << i;
    }
  }
  // quotient may be 2^31 (INT_MIN / 1); negate in 64 bits.
  const auto q = static_cast<std::int64_t>(quotient);
  return static_cast<int>(negative ? -q : q);
}

}  // namespace kata::bitwise_division
