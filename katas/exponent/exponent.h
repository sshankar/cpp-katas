#ifndef KATAS_EXPONENT_EXPONENT_H_
#define KATAS_EXPONENT_EXPONENT_H_

namespace kata::exponent {

// Returns base^exp in O(log |exp|) multiplications (exponentiation by
// squaring), without std::pow. Negative exponents give 1 / base^|exp|.
// Power(x, 0) == 1 for every x.
double Power(double base, int exp);

}  // namespace kata::exponent

#endif  // KATAS_EXPONENT_EXPONENT_H_
