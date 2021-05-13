/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
// @lc code=start
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        int t = 0;
        for (int i = 0; i < n; i++) {
            t = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) { t = max(t, dp[j]); }
            }
            dp[i] = t + 1;
        }
        int res = dp[0];
        for (int i = 0; i < n; i++) { res = max(res, dp[i]); }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}