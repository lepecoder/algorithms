/*
 * @lc app=leetcode.cn id=1928 lang=cpp
 *
 * [1928] 规定时间内到达终点的最小花费
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees) {
        int n = passingFees.size();
        // f[t][i] 恰好使用t分钟到达城市i的最小通行费用
        vector<vector<int>> f(maxTime + 1, vector<int>(n, 0x3f3f3f3f));
        f[0][0] = passingFees[0]; // 初始通行费用
        for (int t = 1; t <= maxTime; t++) {
            for (auto &e : edges) {
                int start = e[0], end = e[1], cost = e[2];
                if (cost <= t) {
                    f[t][start] = min(f[t][start], f[t - cost][end] + passingFees[start]);
                    f[t][end] = min(f[t][end], f[t - cost][start] + passingFees[end]);
                }
            }
        }
    }
};
// @lc code=end

int main() {
    //
    Solution so;
    vector<vector<int>> edges = {{0, 1, 100}};
    vector<int> passfee = {2, 5};
    auto ans = so.minCost(100, edges, passfee);
    cout << ans;
    return 0;
}