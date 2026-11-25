#include "katas/exponent/exponent.h"

namespace kata::exponent {

double Power(double base, int exp) {
  long long e = exp;  // -INT_MIN overflows int.
  if (e < 0) {
    base = 1.0 / base;
    e = -e;
  }
  double result = 1.0;
  while (e > 0) {
    if (e & 1) result *= base;
    base *= base;
    e >>= 1;
  }
  return result;
}

}  // namespace kata::exponent
