/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
// @lc code=start
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        int dp[amount + 1];
        for (int i = 0; i <= amount; i++) dp[i] = -1;
        for (int &e : coins) dp[e] = 1;
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int t = INT_MAX;
            for (int &e : coins) {
                if (i - e >= 0 && dp[i - e] != -1) { t = min(t, dp[i - e] + 1); }
            }
            dp[i] = t == INT_MAX ? -1 : t;
        }
        return dp[amount];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}