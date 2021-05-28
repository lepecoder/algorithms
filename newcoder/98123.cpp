#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int f(int n, int company[], int fitness[]) {
        /* 动态规划，dp[n]表示前n天休息的次数 */
        int dp1[n]; // dp1[k] 表示第k天必须休息, 的前k天休息次数 不能休息就是0x7F
        int dp2[n]; // dp2[k] 表示第k天必须工作
        int dp3[n]; // dp3[k] 表示第k天必须健身
        memset(dp1, 0x7F, sizeof(dp1));
        memset(dp2, 0x7F, sizeof(dp2));
        memset(dp3, 0x7F, sizeof(dp3));
        // int pre = 0;  // 0休息，1公司，-1健身
        if (n == 0) return 0;
        dp1[0] = 1; // 无论如何，第一天都可以休息
        if (company[0] == 1) { dp2[0] = 0; }
        if (fitness[0] == 1) { dp3[0] = 0; }
        for (int i = 1; i < n; i++) {
            // 无论如何，都可以休息，对吧
            dp1[i] = min(dp1[i - 1], min(dp2[i - 1], dp3[i - 1])) + 1;
            if (company[i] == 1) {
                // 可以工作
                dp2[i] = min(dp1[i - 1], dp3[i - 1]);
            }
            if (fitness[i] == 1) {
                // 可以健身
                dp3[i] = min(dp1[i - 1], dp2[i - 1]);
            }
        }
        return min(dp1[n - 1], min(dp2[n - 1], dp3[n - 1]));
    }
};

int main() {
    int n;
    cin >> n;
    int company[n];
    int fitness[n];
    for (int i = 0; i < n; i++) { cin >> company[i]; }
    for (int i = 0; i < n; i++) { cin >> fitness[i]; }
    Solution so;
    int ans = so.f(n, company, fitness);
    cout << ans;
    return 0;
}