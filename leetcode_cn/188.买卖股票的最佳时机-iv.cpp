/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxProfit(int k, vector<int> &prices) {
        /*
        buy[i][j]  前i天完成j笔交易，手上持有股票
        sell[i][j]  。。。。。。。手上没有股票
         */
        int n = prices.size();
        if (n < 2) return 0;
        k = min(k, n / 2);
        int buy[n][k + 1];
        int sell[n][k + 1];
        memset(buy, 0, sizeof(buy));
        memset(sell, 0, sizeof(sell));
        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i <= k; i++) buy[0][i] = sell[0][i] = INT_MIN / 2;
        for (int i = 1; i < n; i++) {
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; j++) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }
        return *max_element(sell[n - 1], sell[n - 1] + k + 1);
        int res = 0;
        for (int j = 0; j <= k; j++) { res = max(res, sell[n - 1][j]); }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}