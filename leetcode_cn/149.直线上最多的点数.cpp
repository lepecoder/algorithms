/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  private:
    double calSlope(vector<vector<int>> &points, int p1, int p2) {
        /* 计算两点间斜率 */
        if (points[p1][0] == points[p2][0]) return 0x3f3f3f3f;
        double slope = (points[p1][1] - points[p2][1]) / (double)(points[p1][0] - points[p2][0]);
        return slope;
    }

  public:
    int maxPoints(vector<vector<int>> &points) {
        unordered_map<int, unordered_map<double, int>> mp; // 直线相同，要求有一个点相同，而且斜率相同
                                                           // index最小的点，斜率，数量
        // unordered_map<double, int> mp;  // slope, count
        // unordered_map<double, int> mp1; // slope, start
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double slope = calSlope(points, i, j);
                mp[i][slope]++;
            }
        }
        int res = 0;
        for (auto &mp1 : mp) {
            for (auto &p : mp1.second) { res = max(res, p.second); }
        }
        return res + 1;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}