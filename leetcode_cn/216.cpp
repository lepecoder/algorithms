/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> res;
    void backtrack(vector<int> path, int idx, int k, int n) {
        /* path是已经选择的数
        idx是数的最后一位，也就是最大的一位
        k是剩余可选的个数
        n是期望的总和 */
        if (k == 0 && n == 0) {
            res.emplace_back(path);
            return;
        }
        if (k <= 0) return;
        for (int i = idx + 1; i <= 9; i++) {
            if (n >= i) {
                path.emplace_back(i);
                backtrack(path, i, k - 1, n - i);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack({}, 0, k, n);
        return res;
    }
};
// @lc code=end

int main() {
    //
    Solution so;
    so.combinationSum3(3, 7);
    return 0;
}