/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  private:
    vector<int> nums;
    vector<vector<int>> res;
    void backtrack(vector<int> &path, int idx) {
        res.emplace_back(path);
        for (int i = idx; i < nums.size(); i++) {
            path.emplace_back(nums[i]);
            backtrack(path, i + 1);
            path.pop_back();
        }
    }

  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        this->nums = nums;
        res.clear();
        vector<int> path;
        backtrack(path, 0);
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}