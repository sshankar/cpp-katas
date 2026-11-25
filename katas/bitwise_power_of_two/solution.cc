#include "katas/bitwise_power_of_two/bitwise_power_of_two.h"

namespace kata::bitwise_power_of_two {

// A power of two has exactly one set bit; n & (n - 1) clears the lowest one.
bool IsPowerOfTwo(std::uint64_t n) { return n != 0 && (n & (n - 1)) == 0; }

}  // namespace kata::bitwise_power_of_two
