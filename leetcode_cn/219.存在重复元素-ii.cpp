/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (st.count(nums[i])) return true;
            st.emplace(nums[i]);
            if (i >= k) st.erase(nums[i - k]);
        }
        return false;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}