/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
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
    int countSquares(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m]; // 以matrix[i][j]为右下角的最大正方形边长
        int res = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 1) {
                dp[i][0] = 1;
                res++;
            }
        }
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 1) {
                dp[0][j] = 1;
                res++;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    res += dp[i][j];
                }
                // res = max(res, dp[i][j]);
            }
        }

        return res * res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}