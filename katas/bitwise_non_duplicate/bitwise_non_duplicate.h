#ifndef KATAS_BITWISE_NON_DUPLICATE_BITWISE_NON_DUPLICATE_H_
#define KATAS_BITWISE_NON_DUPLICATE_BITWISE_NON_DUPLICATE_H_

#include <vector>

namespace kata::bitwise_non_duplicate {

// Every element of nums appears exactly twice except one, which appears once.
// Returns that element in O(n) time and O(1) extra space.
// Precondition: nums is non-empty and well-formed.
int FindNonDuplicate(const std::vector<int>& nums);

}  // namespace kata::bitwise_non_duplicate

#endif  // KATAS_BITWISE_NON_DUPLICATE_BITWISE_NON_DUPLICATE_H_
