/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int idx;
        for (idx = n - 2; idx >= 0; idx--) {
            if (nums[idx] < nums[idx + 1]) break;
        }
        if (idx == -1) { // 不存在下一个更大的排列
            // sort(nums.begin(), nums.end());
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = n - 1;
        while (j > idx && nums[j] <= nums[idx]) j--;
        swap(nums[idx], nums[j]);
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
// @lc code=end

int main() {
    //
    return 0;
}