/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0;          // 第0天手里没有股票
        dp[0][1] = -prices[0]; // 第0天手里有股票
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
