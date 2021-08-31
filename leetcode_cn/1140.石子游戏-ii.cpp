/*
 * @lc app=leetcode.cn id=1140 lang=cpp
 *
 * [1140] 石子游戏 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int stoneGameII(vector<int> &piles) {
        int n = piles.size(), sum = 0;
        int dp[n][n + 1]; // dp[i][j], 剩余[i,n-1]堆，M=j时，先取的可以获得的最大石子数量
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; --i) {
            sum += piles[i];
            for (int m = 1; m <= n; ++m) {
                if (i + 2 * m >= n) {
                    dp[i][m] = sum;
                } else {
                    for (int j = 1; j <= 2 * m; j++) { dp[i][m] = max(dp[i][m], sum - dp[i + j][max(j, m)]); }
                }
            }
        }
        return dp[0][1];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}