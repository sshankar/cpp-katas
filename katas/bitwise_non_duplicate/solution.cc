#include "katas/bitwise_non_duplicate/bitwise_non_duplicate.h"

namespace kata::bitwise_non_duplicate {

// x ^ x == 0 and x ^ 0 == x, so pairs cancel out.
int FindNonDuplicate(const std::vector<int>& nums) {
  int result = 0;
  for (int n : nums) result ^= n;
  return result;
}

}  // namespace kata::bitwise_non_duplicate
