/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
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
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

int main() {
    Solution so;
    int res = so.longestPalindromeSubseq("bbbab");
    cout << res;
    return 0;
}