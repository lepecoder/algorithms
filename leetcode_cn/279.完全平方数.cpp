/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0, dp[1] = 1;
        int t;
        vector<int> squlist; // 完全平方数列表
        // squlist.emplace_back(1);
        for (int i = 2; i <= n; i++) {
            // 如果i是完全平方数，添加到squlist
            dp[i] = 1 + dp[i - 1];
            if (int(sqrt(i)) * int(sqrt(i)) == i) squlist.emplace_back(i);
            for (auto &x : squlist) { dp[i] = min(dp[i], 1 + dp[i - x]); }
            cout << i << ' ' << dp[i] << endl;
        }
        return dp[n];
    }
};
// @lc code=end

int main() {
    Solution so;
    int res = so.numSquares(12);
    return 0;
}