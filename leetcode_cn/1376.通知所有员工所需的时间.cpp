/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 *
 * [1376] 通知所有员工所需的时间
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int fun(vector<int> &times, int idx, vector<int> &manager, vector<int> &informTime) {
        // if (idx == -1) return 0;
        if (times[idx] == -1) { times[idx] = fun(times, manager[idx], manager, informTime) + informTime[manager[idx]]; }
        return times[idx];
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        vector<int> times(n, -1);
        times[headID] = 0;
        for (int i = 0; i < n; i++) fun(times, i, manager, informTime);
        return *max_element(times.begin(), times.end());
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
