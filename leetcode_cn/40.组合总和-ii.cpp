/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> res;
    void backtrack(vector<int> path, vector<int> &candi, int idx, int target) {
        if (target == 0) {
            res.emplace_back(path);
            return;
        }
        for (int i = idx; i < candi.size(); i++) {
            if (candi[i] <= target) {
                if (i == idx || candi[i] != candi[i - 1]) {
                    path.emplace_back(candi[i]);
                    backtrack(path, candi, i + 1, target - candi[i]);
                    path.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        backtrack({}, candidates, 0, target);
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}