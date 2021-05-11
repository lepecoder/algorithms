/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
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
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        // 最后一行赋初值
        for (int j = 0; j < m; j++) dp[n - 1][j] = matrix[n - 1][j];
        // 自下向上递归
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = dp[i + 1][j] + matrix[i][j];
                if (j > 0) { dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + matrix[i][j]); }
                if (j < m - 1) { dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + matrix[i][j]); }
            }
        }
        int res = dp[0][0];
        for (int j = 1; j < m; j++) res = min(res, dp[0][j]);
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}