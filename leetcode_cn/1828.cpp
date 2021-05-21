/*
 * @lc app=leetcode.cn id=1828 lang=cpp
 *
 * [1828] 统计一个圆中点的数目
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
  private:
    double euclidean_distance(int xi, int yi, int xj, int yj) {
        /* 计算两点间欧氏距离 */
        int t = pow((xi - xj), 2) + pow((yi - yj), 2);
        return sqrt(t);
    }

  public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries) {
        int n = queries.size();
        vector<int> res(n, 0);
        int k = -1;
        for (auto &q : queries) {
            k++;
            for (auto &p : points) {
                double t = euclidean_distance(q[0], q[1], p[0], p[1]);
                if (t <= q[2]) { res[k]++; }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<vector<int>> points = {{1, 3}, {3, 3}, {5, 3}, {2, 2}};
    vector<vector<int>> queries = {{2, 3, 1}, {4, 3, 1}, {1, 1, 2}};
    so.countPoints(points, queries);
    return 0;
}