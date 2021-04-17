/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        set<int> st(nums.begin(), nums.end());
        return st.size() != nums.size();
    }
};
// @lc code=end

int main() {
    //
    return 0;
}