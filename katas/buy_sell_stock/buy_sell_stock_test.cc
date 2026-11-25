#include "katas/buy_sell_stock/buy_sell_stock.h"

#include <gtest/gtest.h>

namespace kata::buy_sell_stock {
namespace {

TEST(BuySellStockTest, Classic) {
  EXPECT_EQ(MaxProfit({7, 1, 5, 3, 6, 4}), 5);
}

TEST(BuySellStockTest, BestBuyAfterEarlierPeak) {
  EXPECT_EQ(MaxProfit({2, 4, 1, 7}), 6);
  EXPECT_EQ(MaxProfit({3, 8, 1, 2}), 5);
}

TEST(BuySellStockTest, Rising) { EXPECT_EQ(MaxProfit({1, 2, 3, 4, 5}), 4); }

TEST(BuySellStockTest, FallingMeansNoTrade) {
  EXPECT_EQ(MaxProfit({7, 6, 4, 3, 1}), 0);
}

TEST(BuySellStockTest, TooFewDays) {
  EXPECT_EQ(MaxProfit({}), 0);
  EXPECT_EQ(MaxProfit({5}), 0);
}

}  // namespace
}  // namespace kata::buy_sell_stock
