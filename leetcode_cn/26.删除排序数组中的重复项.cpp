/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int i, j, n = nums.size();
        if (n < 2) return n;
        int pre = nums[0];
        for (i = 1, j = 1; j < n; j++) {
            if (nums[j] != pre) {
                nums[i++] = nums[j];
                pre = nums[j];
            }
        }
        return i;
    }
};
// @lc code=end

int main() {
    // k
    return 0;
}