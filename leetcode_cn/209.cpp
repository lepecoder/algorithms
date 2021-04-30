/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();
        int p1 = 0, p2 = 0; // 滑动窗口边界，两端包含
        int t_sum = nums[0];
        int res = 1 << 30;
        while (p2 < n - 1) {
            // if(t_sum >= target) res = min(res, p2-p1);
            while (t_sum < target && p2 < n - 1) { // 还没到目标值，向右增大滑动窗口
                p2++;
                // if (p2>=n)
                t_sum += nums[p2];
            }
            // 此时滑动窗口内元素已满足条件，尝试减小左边界
            while (t_sum >= target) {
                t_sum -= nums[p1];
                p1++;
            }
            res = min(res, p2 - p1 + 2);
        }
        if (res > n) return 0;
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> nums = {1, 1, 1, 1};
    int res = so.minSubArrayLen(7, nums);
    cout << res;
    return 0;
}