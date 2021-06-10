/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        /* 求不同面额的硬币可以凑成的amount的组合数 */
        int n = coins.size();
        int dp[amount + 1]; // 金额k的组合数
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int &coin : coins) { // 金额顺序递增，不会出现重复组合数
            for (int i = coin; i <= amount; i++) { dp[i] += dp[i - coin]; }
        }
        return dp[amount];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}