/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool canCross(vector<int> &stones) {
        int n = stones.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i < n; i++) { // 第i个位置最多跳i
            if (stones[i] - stones[i - 1] > i) return false;
        }
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) { // 从第j个位置跳到第i个位置
                int k = stones[i] - stones[j];
                if (k > j + 1) break;
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if (i == n - 1 && dp[i][k] == true) return true;
            }
        }
        return false;
    }
};

// @lc code=end

int main() {
    Solution so;
    vector<int> stones = {0, 1, 3, 4, 5, 7, 9, 10, 12};
    bool ans = so.canCross(stones);
    cout << ans;
    return 0;
}