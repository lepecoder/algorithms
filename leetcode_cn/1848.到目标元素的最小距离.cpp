/*
 * @lc app=leetcode.cn id=1848 lang=cpp
 *
 * [1848] 到目标元素的最小距离
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int getMinDistance(vector<int> &nums, int target, int start) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i + start < n && nums[i + start] == target) { return i; }
            if (start - i >= 0 && nums[start - i] == target) return i;
        }
        return -1;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}