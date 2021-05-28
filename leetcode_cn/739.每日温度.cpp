/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<pair<int, int>> stk;
        int n = temperatures.size();
        vector<int> res(n, 0);
        int e;
        for (int i = 0; i < n; i++) {
            e = temperatures[i];
            while (!stk.empty() && e > stk.top().second) {
                pair<int, int> p = stk.top();
                res[p.first] = i - p.first;
                stk.pop();
            }
            stk.push({i, e});
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
