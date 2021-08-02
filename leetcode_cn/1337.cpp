/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        vector<int> res;
        int n = mat.size();
        if (n == 0) return res;
        int m = mat[0].size();
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            int t = accumulate(mat[i].begin(), mat[i].end(), 0);
            v.emplace_back(vector<int>{i, t});
        }
        stable_sort(v.begin(), v.end(), [](auto &v1, auto &v2) { return v1[1] < v2[1]; });
        // sort(v.begin(), v.end(), [](const vector<int> &v1, const vector<int> &v2) { return (v1[1] == v2[1] && v1[0] < v2[0]) || v1[1] < v2[1]; });
        // for (auto &x : v) { cout << x[0] << "--" << x[1] << endl; }
        for (int i = 0; i < k; i++) { res.emplace_back(v[i][0]); }
        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> r;
    r.emplace_back(vector<int>{10, 10});
    r.emplace_back(11, 11);
    vector<vector<int>> mat{{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};
    Solution so;
    so.kWeakestRows(mat, 3);
    return 0;
}