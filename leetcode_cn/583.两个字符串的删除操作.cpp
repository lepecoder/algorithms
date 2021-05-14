/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
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
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++) { dp[i][0] = i; }
        for (int j = 0; j <= m; j++) { dp[0][j] = j; }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}