/*
 * @lc app=leetcode.cn id=1269 lang=cpp
 *
 * [1269] 停在原地的方案数
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
    const int MODULO = 1000000007;
    int numWays(int steps, int arrLen) {
        int maxColumn = min(arrLen - 1, steps);
        int dp[steps + 1][maxColumn];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= maxColumn; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MODULO;
                if (j < maxColumn) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MODULO;
            }
        }
        return dp[steps][0];
    }
};
// @lc code=end

int main() {
    Solution so;
    int res = so.numWays(3, 2);
    cout << res;
    return 0;
}