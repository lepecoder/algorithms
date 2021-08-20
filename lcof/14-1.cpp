#include <bits/stdc++.h>
using namespace std;
class Solution1 {
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

class Solution {
  public:
    int cuttingRope(int n) {
        if (n <= 3) return 1;
        int y = n % 3;
        int x = n / 3;
        if (y == 0) { return x * x * x; }
        if (y == 1) { return x * x * (x + 1); }
        if (y == 2) { return x * (x + 1) * (x + 1); }
    }
};
int main() {
    //
    return 0;
}