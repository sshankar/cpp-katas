#ifndef KATAS_BITWISE_CHECK_SET_BITWISE_CHECK_SET_H_
#define KATAS_BITWISE_CHECK_SET_BITWISE_CHECK_SET_H_

#include <cstdint>

namespace kata::bitwise_check_set {

// Returns true if bit `bit` (0 = least significant) of `value` is 1.
// Precondition: 0 <= bit < 32.
bool IsBitSet(std::uint32_t value, int bit);

}  // namespace kata::bitwise_check_set

#endif  // KATAS_BITWISE_CHECK_SET_BITWISE_CHECK_SET_H_
