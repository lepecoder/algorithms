/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
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
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int dp[n + 1][m + 1];
        // memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        for (int j = 1; j <= m; j++) { dp[0][j] = dp[0][j - 1] + int(s2[j - 1]); }
        for (int i = 1; i <= n; i++) { dp[i][0] = dp[i - 1][0] + int(s1[i - 1]); }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] != s2[j - 1]) { // 注定要删除一个
                    dp[i][j] = min(dp[i - 1][j] + int(s1[i - 1]), dp[i][j - 1] + int(s2[j - 1]));
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

int main() {
    char s = 's';
    cout << int(s);
    return 0;
}