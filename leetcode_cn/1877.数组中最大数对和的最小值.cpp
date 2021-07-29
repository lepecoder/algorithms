/*
 * @lc app=leetcode.cn id=1877 lang=cpp
 *
 * [1877] 数组中最大数对和的最小值
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int minPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int t = nums[l] + nums[r];
            res = max(t, res);
            l++;
            r--;
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
