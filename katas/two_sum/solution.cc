#include "katas/two_sum/two_sum.h"

#include <unordered_map>

namespace kata::two_sum {

std::optional<std::pair<std::size_t, std::size_t>> TwoSum(
    const std::vector<int>& nums, int target) {
  std::unordered_map<long long, std::size_t> seen;  // value -> index
  for (std::size_t j = 0; j < nums.size(); ++j) {
    // 64-bit so target - nums[j] can't overflow.
    long long complement = static_cast<long long>(target) - nums[j];
    if (auto it = seen.find(complement); it != seen.end()) {
      return std::pair{it->second, j};
    }
    seen.emplace(nums[j], j);
  }
  return std::nullopt;
}

}  // namespace kata::two_sum
