/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int countSubstrings(string s) {
        /* 统计字符串中的回文子串个数 */
        int n = s.length();
        bool dp[n][n]; // 记录由a-b是否是回文串
        // memset(dp,0,sizeof(dp));
        for (int i = 0; i < n; i++) {
            //
            dp[i][i] = true;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (i + 1 < j - 1) {
                        dp[i][j] = dp[i + 1][j - 1];
                    } else {
                        dp[i][j] = true;
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dp[i][j]) res++;
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}