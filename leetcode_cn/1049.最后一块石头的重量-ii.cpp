#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int lastStoneWeightII(vector<int> &stones) {
        int n = stones.size();
        int total = accumulate(stones.begin(), stones.end(), 0);
        int m = total / 2;
        bool dp[n + 1][m + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j < stones[i]) {
                    dp[i + 1][j] = dp[i][j];
                } else {
                    dp[i + 1][j] = dp[i][j] || dp[i][j - stones[i]];
                }
            }
        }
        for (int j = m;; j--) {
            if (dp[n][j]) return total - 2 * j;
        }
    }
};
int main() {
    //
    return 0;
}