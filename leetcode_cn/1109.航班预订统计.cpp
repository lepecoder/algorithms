/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        // 定义查分数组，diff[i] = res[i]-res[i-1]
        // 那么原数组 res[i] = res[i-1]+diff[i]
        vector<int> diff(n + 2, 0);
        // vector<res
        for (vector<int> &v : bookings) {
            diff[v[0]] += v[2];
            diff[v[1] + 1] -= v[2];
        }
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; i++) { res[i] = res[i - 1] + diff[i]; }
        return vector<int>(res.begin() + 1, res.end());
    }
};
// @lc code=end

int main() {
    //
    vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    Solution so;
    vector<int> ans = so.corpFlightBookings(bookings, 5);
    return 0;
}