/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int res = 0;
        int dp[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { dp[i][j] = INT_MAX; }
        }
        dp[n - 1][m - 1] = 1; // 最后的点数至少是1
        // dp[n-1][m-1]+=dungeon[n-1][m-1];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // 可以被右边更新
                if (i + 1 < n) { dp[i][j] = min(dp[i][j], dp[i + 1][j] - dungeon[i + 1][j]); }
                // 可以被下边更新
                if (j + 1 < m) { dp[i][j] = min(dp[i][j], dp[i][j + 1] - dungeon[i][j + 1]); }
                dp[i][j] = max(dp[i][j], 1);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { cout << dp[i][j] << ' '; }
            cout << endl;
        }
        return max(dp[0][0] - dungeon[0][0], 1);
    }
};
// @lc code=end

int main() {
    //
    return 0;
}