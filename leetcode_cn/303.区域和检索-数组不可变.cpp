/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class NumArray {
  public:
    int n;
    int *arr;
    NumArray(vector<int> &nums) {
        n = nums.size();
        arr = new int[1 + n];
        arr[0] = 0;
        for (int i = 0; i < n; i++) { arr[i + 1] = nums[i] + arr[i]; }
    }

    int sumRange(int left, int right) { return arr[right + 1] - arr[left]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

int main() {
    //
    return 0;
}