#ifndef KATAS_BITWISE_POWER_OF_TWO_BITWISE_POWER_OF_TWO_H_
#define KATAS_BITWISE_POWER_OF_TWO_BITWISE_POWER_OF_TWO_H_

#include <cstdint>

namespace kata::bitwise_power_of_two {

// Returns true if n is a power of two, in O(1) using bit operations (no loops).
// Zero is not a power of two.
bool IsPowerOfTwo(std::uint64_t n);

}  // namespace kata::bitwise_power_of_two

#endif  // KATAS_BITWISE_POWER_OF_TWO_BITWISE_POWER_OF_TWO_H_
