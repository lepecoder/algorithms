/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool stoneGame(vector<int> &piles) {
        int n = piles.size();
        int dp[n][n];
        for (int i = 0; i < n; ++i) dp[i][i] = piles[i];
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) { dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]); }
        }
        return dp[0][n - 1] > 0;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}