#include "katas/bitwise_check_set/bitwise_check_set.h"

namespace kata::bitwise_check_set {

bool IsBitSet(std::uint32_t value, int bit) { return (value >> bit) & 1u; }

}  // namespace kata::bitwise_check_set
