/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int dp[110];
    int n;
    int dpDec(string s, int idx) {
        /* 从s的第idx位之后可以解码的数量 */
        if (idx >= n) return 1;
        if (dp[idx] != -1) return dp[idx];
        dp[idx] = 0;
        /* 一位解码 */
        if (s[idx] >= '1' && s[idx] <= '9') { dp[idx] += dpDec(s, idx + 1); }
        /* 两位解码 */
        if (idx < n - 1) {
            if ((s[idx] == '1' && s[idx + 1] >= '0' && s[idx + 1] <= '9') || (s[idx] == '2' && s[idx + 1] >= '0' && s[idx + 1] <= '6')) {
                dp[idx] += dpDec(s, idx + 2);
            }
        }
        return dp[idx];
    }

    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        n = s.size();
        int res = dpDec(s, 0);

        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    int ans = so.numDecodings("111");
    int a = 1, b = 2, c = 3;
    tie(a, b) = {b, c};
    cout << a << ' ' << b << ' ' << c;

    return 0;
}