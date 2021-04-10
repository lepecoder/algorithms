/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int findMin(vector<int> &nums) {
        // return the minimum element in nums
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[j] > nums[i]) { // 单调的，最左就是最小值
                return nums[i];
            } else { // 中间有旋转
                int mid = (i + j) / 2;
                if (nums[mid] > nums[j]) // 分割点在mid右侧
                    i = mid + 1;
                else if (nums[mid] == nums[i]) {
                    // return nums[i];
                    i++;
                } else { // 分割点在mid上，及左侧
                    j = mid;
                }
            }
        }
        return nums[i];
    }
};

// @lc code=end

int main() {
    //
    Solution so;
    vector<int> v{3, 3, 1, 3};
    int ans = so.findMin(v);
    cout << ans;
    return 0;
}