#ifndef KATAS_TWO_SUM_TWO_SUM_H_
#define KATAS_TWO_SUM_TWO_SUM_H_

#include <cstddef>
#include <optional>
#include <utility>
#include <vector>

namespace kata::two_sum {

// Returns indices {i, j}, i < j, with nums[i] + nums[j] == target, or
// std::nullopt if no such pair exists. Assumes at most one valid pair.
// Aim for O(n) time.
std::optional<std::pair<std::size_t, std::size_t>> TwoSum(
    const std::vector<int>& nums, int target);

}  // namespace kata::two_sum

#endif  // KATAS_TWO_SUM_TWO_SUM_H_
