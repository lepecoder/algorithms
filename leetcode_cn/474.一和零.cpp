/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  private:
    int res;
    pair<int, int> count01(string str) {
        int c0 = 0, c1 = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0') {
                c0++;
            } else {
                c1++;
            }
        }
        return {c0, c1};
    }

  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        /* 动态规划
        使用dp[k][m][n] 表示前k个字符串包含m个0，n个1的最大子集数量
         */
        int k = strs.size();
        int dp[k + 1][m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < k; i++) {
            auto p = count01(strs[i]);
            for (int j = 0; j <= m; j++) {
                for (int l = 0; l <= n; l++) {
                    dp[i + 1][j][l] = dp[i][j][l];
                    if (j >= p.first && l >= p.second) dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j - p.first][l - p.second] + 1);
                }
            }
        }
        return dp[k][m][n];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}