#ifndef KATAS_BUY_SELL_STOCK_BUY_SELL_STOCK_H_
#define KATAS_BUY_SELL_STOCK_BUY_SELL_STOCK_H_

#include <vector>

namespace kata::buy_sell_stock {

// prices[i] is a stock's price on day i. Returns the maximum profit from
// buying once and selling once on a later day, or 0 if no profit is possible.
// Aim for one pass.
int MaxProfit(const std::vector<int>& prices);

}  // namespace kata::buy_sell_stock

#endif  // KATAS_BUY_SELL_STOCK_BUY_SELL_STOCK_H_
