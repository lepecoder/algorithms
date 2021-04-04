/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

// @lc code=start
class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        if (n > m) {
            swap(n, m);
            swap(text1, text2);
        }
        int dp[n + 1];
        int p1 = 0, p2 = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++) {
            char ti = text1[i - 1];
            p1 = 0;
            for (int j = 1; j <= n; j++) {
                char tj = text2[j - 1];
                p2 = dp[j];
                dp[j] = ti == tj ? p1 + 1 : max(dp[j], dp[j - 1]);
                // if (ti == tj) {
                // dp[i][j] = dp[i - 1][j - 1] + 1;
                // dp[j] = p1 + 1;
                // } else {
                // dp[0][j] = max(dp[i- 1][j], dp[i][j - 1]);
                // dp[j] = max(dp[j], dp[j - 1]);
                // }
                p1 = p2;
            }
        }
        return dp[n];
    }
};
// @lc code=end

int main() {
    //
    string text2 = "abcba", text1 = "abcbcba";
    Solution so;
    int ans = so.longestCommonSubsequence(text1, text2);
    cout << ans;
    return 0;
}