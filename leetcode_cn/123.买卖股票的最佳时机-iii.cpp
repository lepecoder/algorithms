/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int buy1 = -prices[0], sell1 = 0; // 第0天买入卖出
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; i++) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}