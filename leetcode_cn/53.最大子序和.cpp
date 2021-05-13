/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
// @lc code=start
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int pre = 0, res = nums[0];
        for (const int &e : nums) {
            pre = max(pre + e, e);
            res = max(res, pre);
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}