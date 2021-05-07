/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        int dp_max[n];
        int dp_min[n];
        memset(dp_max, 0, sizeof(dp_max));
        memset(dp_min, 0, sizeof(dp_min));
        dp_max[0] = dp_min[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            dp_max[i] = max(dp_max[i - 1] * nums[i], max(dp_min[i - 1] * nums[i], nums[i]));
            dp_min[i] = min(dp_max[i - 1] * nums[i], min(dp_min[i - 1] * nums[i], nums[i]));
            res = max(res, max(dp_max[i], dp_min[i]));
        }
        return res;
    }
};
// @lc code=end

int main() {
    int dp[30];
    cout << sizeof(dp);
    return 0;
}