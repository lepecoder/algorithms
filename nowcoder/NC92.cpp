#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    int n, m;
    string LCS(string s1, string s2) {
        // write code here
        n = s1.size(), m = s2.size();
        int dp[n + 1][m + 1];
        int dir[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s1[i] == s2[j]) {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                    dir[i + 1][j + 1] = 1; // 来自左上方
                } else if (dp[i + 1][j] > dp[i][j + 1]) {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                    dir[i + 1][j + 1] = 3; // 来自左边
                    // dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                } else {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                    dir[i + 1][j + 1] = 2; // 来自右边
                }
            }
        }
        string res = "";
        for (int i = n, j = m; dp[i][j] >= 1;) {
            if (s1[i - 1] == s2[j - 1]) {
                res += s1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] >= dp[i][j - 1])
                i--;
            else
                j--;
        }
        reverse(res.begin(), res.end());
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= m; j++) { cout << dp[i][j] << ' '; }
        //     cout << endl;
        // }
        return res.empty() ? "-1" : res;
    }
};
int main() {
    Solution so;
    string s1 = "1A2C3D4B56", s2 = "B1D23A456A";
    string ans = so.LCS(s1, s2);
    cout << ans << endl;
    return 0;
}