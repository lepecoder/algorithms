#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int cuttingRope(int n) {
        int dp[n + 1]; // 将k拆分成两个数的最大乘积
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            int curmax = 0;
            for (int j = 1; j < i; j++) { curmax = max(curmax, max(j * (i - j), j * dp[i - j])); }
            dp[i] = curmax;
        }
        return dp[n];
    }
};
int main() {
    //
    return 0;
}