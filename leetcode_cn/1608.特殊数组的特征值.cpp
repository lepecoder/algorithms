/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int specialArray(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n <= nums[0]) { return n; }
        int res = nums[0];
        int idx = 0; // idx指向大于等于res的第一个元素
        while (res < n && idx < n) {
            while (idx < n && nums[idx] < res) idx++;
            if (idx == n) return -1;
            if (n - idx == res) return res;
            // if (nums[idx] == res && n-idx+1==res) return res;
            res++;
        }
        return -1;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}