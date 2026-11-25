#ifndef KATAS_BITWISE_ADDITION_BITWISE_ADDITION_H_
#define KATAS_BITWISE_ADDITION_BITWISE_ADDITION_H_

namespace kata::bitwise_addition {

// Returns a + b without using the + or - operators (or ++/--, +=, -=).
// Overflow wraps around (two's complement).
int Add(int a, int b);

}  // namespace kata::bitwise_addition

#endif  // KATAS_BITWISE_ADDITION_BITWISE_ADDITION_H_
