/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> ans;
    vector<int> *p_nums;
    int n;
    void backtrack(vector<int> &path, int idx) {
        // 从第idx个元素开始添加
        ans.push_back(path);
        for (int i = idx; i < n; i++) {
            if (i == idx || p_nums->at(i - 1) != p_nums->at(i)) {
                path.push_back(p_nums->at(i));
                backtrack(path, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        p_nums = &nums;
        vector<int> path;
        backtrack(path, 0);
        return ans;
    }
    void show() {
        for (auto v = ans.begin(); v != ans.end(); v++) {
            for (auto it = v->begin(); it != v->end(); it++) { cout << *it << ' '; }
            cout << endl;
        }
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> v{1, 2, 2, 3, 4};
    so.subsetsWithDup(v);
    so.show();
    return 0;
}