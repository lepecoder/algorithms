#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) return 0;
        int n = nums.size(), neg = diff / 2;
        int dp[n + 1][neg + 1]; // 前n个数组成neg的方案数
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= num) { dp[i][j] += dp[i - 1][j - num]; }
            }
        }
        return dp[n][neg];
    }
};

int main() {
    //
    return 0;
}