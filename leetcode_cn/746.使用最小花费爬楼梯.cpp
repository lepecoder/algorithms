/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        int dp[n + 1]; // 达到i阶梯的最低花费
        dp[0] = 0;
        dp[1] = cost[0];
        for (int i = 1; i < n; i++) { dp[i + 1] = min(dp[i], dp[i - 1]) + cost[i]; }
        return min(dp[n - 1], dp[n]);
    }
};
// @lc code=end

int main() {
    int n = 3;
    int a = pow(10, 3);
    cout << a;
    return 0;
}