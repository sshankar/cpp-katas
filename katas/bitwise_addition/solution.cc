#include "katas/bitwise_addition/bitwise_addition.h"

#include <cstdint>

namespace kata::bitwise_addition {

// XOR adds without carry; AND finds the carry bits, which move one place left.
// Unsigned arithmetic keeps the left shift of negative values well-defined.
int Add(int a, int b) {
  auto sum = static_cast<std::uint32_t>(a);
  auto carry = static_cast<std::uint32_t>(b);
  while (carry != 0) {
    std::uint32_t next_carry = (sum & carry) << 1;
    sum ^= carry;
    carry = next_carry;
  }
  return static_cast<int>(sum);
}

}  // namespace kata::bitwise_addition
