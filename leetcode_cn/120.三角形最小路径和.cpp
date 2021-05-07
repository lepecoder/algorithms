/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        int dp[m];
        for (int i = 0; i < m; i++) { dp[i] = triangle[n - 1][i]; }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) { dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]); }
        }
        return dp[0];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}