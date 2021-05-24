/*
 * @lc app=leetcode.cn id=664 lang=cpp
 *
 * [664] 奇怪的打印机
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int strangePrinter(string s) {
        int n = s.length();
        int dp[n][n];
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    int minn = INT_MAX;
                    for (int k = i; k < j; k++) { minn = min(minn, dp[i][k] + dp[k + 1][j]); }
                    dp[i][j] = minn;
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}