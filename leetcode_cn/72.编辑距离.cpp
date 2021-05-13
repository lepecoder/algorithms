/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
class Solution {
  public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        // int dp[n1 + 1][n2 + 1];
        // int **dp = new int *[n1 + 1]; // 建立指针数组
        // for (int i = 0; i <= n1; i++) { dp[i] = new int[n2 + 1]; }
        int *p_arr = new int[(n1 + 1) * (n2 + 1)];
        int(*dp)[n2 + 1] = (int(*)[n2 + 1]) p_arr;
        // memset(dp, 0, sizeof(int) * (n1 + 1) * (n2 + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= n1; i++) dp[i][0] = i;
        for (int j = 1; j <= n2; j++) dp[0][j] = j;
        // 自底向上的求解
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1), dp[i][j - 1] + 1);
                }
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end

int main() {
    //
    return 0;
}