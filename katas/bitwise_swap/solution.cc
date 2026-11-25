#include "katas/bitwise_swap/bitwise_swap.h"

namespace kata::bitwise_swap {

void Swap(int& a, int& b) {
  if (&a == &b) return;  // x ^= x would zero the value.
  a ^= b;
  b ^= a;
  a ^= b;
}

}  // namespace kata::bitwise_swap
