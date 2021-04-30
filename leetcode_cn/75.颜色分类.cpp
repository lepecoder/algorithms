/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        int idx0 = 0;     // 左侧，不包含，全都是0
        int idx2 = n - 1; // 右侧，不包含，全都是2
        while (idx0 < n && nums[idx0] == 0) idx0++;
        while (idx2 >= 0 && nums[idx2] == 2) idx2--;
        int i = idx0;
        while (i <= idx2) {
            // for(int i=idx0;i<=idx2;i++){
            if (nums[i] == 0) {
                if (i != idx0) {
                    swap(nums[i], nums[idx0]);
                    idx0++;
                } else {
                    idx0++;
                    i++;
                }
            } else if (nums[i] == 2) {
                if (i != idx2) {
                    swap(nums[i], nums[idx2]);
                    idx2--;
                } else {
                    idx2--;
                    i++;
                }
            } else {
                i++;
            }
        }
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> nums = {1, 0, 1};
    so.sortColors(nums);
    for (int &x : nums) { cout << x << ' '; }
    return 0;
}