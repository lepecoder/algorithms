/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * [1838] 最高频元素的频数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int pre[n + 1];
        pre[0] = 0;
        for (int i = 1; i <= n; i++) { pre[i] = pre[i - 1] + nums[i - 1]; }
        int res = 0;
        for (int i = 0; i < n; i++) {
            // 二分查找能够扩展的最远距离
            int l = i, r = n;
            while (l < r) {
                if (l == n) break;
                int m = l + (r - l) / 2;
                int t = nums[m] * (m - l) - (pre[m] - pre[l - 1]);
                // 找到第一个不满足条件的，之前的应该都满足
                if (t <= k) { // 满足
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            // 现在l就是从i开始能覆盖的最大的距离
            cout << i << ' ' << l << endl;
            res = max(res, l - i);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> nums = {1, 4, 8, 13};
    int ans = so.maxFrequency(nums, 5);
    cout << ans;
    return 0;
}