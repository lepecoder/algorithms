/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int m = nums.size();
        if (m < 2) return false;
        unordered_map<int, int> mp; // 记录前N项和对k的余数第一次出现的下标位置
        mp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < m; i++) {
            remainder = (remainder + nums[i]) % k;
            if (mp.count(remainder)) {
                int preIndex = mp[remainder];
                if (i - preIndex >= 2) { return true; }
            } else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}