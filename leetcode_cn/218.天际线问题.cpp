/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<vector<int>> res;
        /*
        因为关键点只能是建筑物的左右两边，所以我们只考虑建筑物的边缘，那么横坐标就是建筑边缘，纵坐标就是最大高度
         */
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) -> bool { return a.second < b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        vector<int> boundaries;
        for (auto &building : buildings) {
            boundaries.emplace_back(buildings[0]);
            boundaries.emplace_back(buildings[1]);
        }
        sort(boundaries.begin(), boundaries.end());
        vector<vector<int>> res;
        int n = buildings.size(), idx = 0;
        for (auto &boundary : boundaries) {
            while (idx < n && buildings[idx][0] <= boundary) { que. }
        }
    }
};
// @lc code=end

int main() {
    //
    return 0;
}