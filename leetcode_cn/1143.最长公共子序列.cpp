/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++) {
            char ti = text1[i - 1];
            for (int j = 1; j <= n; j++) {
                char tj = text2[j - 1];
                if (ti == tj) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

int main() {
    //
    string text1 = "abcde", text2 = "ace";
    Solution so;
    int ans = so.longestCommonSubsequence(text1, text2);
    cout << ans;
    return 0;
}