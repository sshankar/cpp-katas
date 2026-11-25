#include "katas/buy_sell_stock/buy_sell_stock.h"

#include <algorithm>
#include <climits>

namespace kata::buy_sell_stock {

// Track the cheapest price so far; the best sale today is price - cheapest.
int MaxProfit(const std::vector<int>& prices) {
  int cheapest = INT_MAX;
  int best = 0;
  for (int price : prices) {
    cheapest = std::min(cheapest, price);
    best = std::max(best, price - cheapest);
  }
  return best;
}

}  // namespace kata::buy_sell_stock
