/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @lc code=start
class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (r == n || nums[l] != target) { return {-1, -1}; }
        int a = l;
        if (a == -1) return {-1, -1};
        l = 0, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int b = l - 1;
        return {a, b};
    }
};
// @lc code=end

int main() {
    //
    return 0;
}