#ifndef KATAS_BITWISE_DIVISION_BITWISE_DIVISION_H_
#define KATAS_BITWISE_DIVISION_BITWISE_DIVISION_H_

namespace kata::bitwise_division {

// Returns dividend / divisor truncated toward zero, without using *, / or %.
// The one overflowing case, INT_MIN / -1, returns INT_MAX.
// Precondition: divisor != 0.
int Divide(int dividend, int divisor);

}  // namespace kata::bitwise_division

#endif  // KATAS_BITWISE_DIVISION_BITWISE_DIVISION_H_
