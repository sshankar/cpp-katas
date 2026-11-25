#ifndef KATAS_BITWISE_SWAP_BITWISE_SWAP_H_
#define KATAS_BITWISE_SWAP_BITWISE_SWAP_H_

namespace kata::bitwise_swap {

// Swaps a and b in place using XOR only: no temporary, no std::swap.
// Must also work when a and b refer to the same object.
void Swap(int& a, int& b);

}  // namespace kata::bitwise_swap

#endif  // KATAS_BITWISE_SWAP_BITWISE_SWAP_H_
