/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> res;
        res.reserve(numCourses);
        vector<int> indeg;
        vector<vector<int>> edges;
        indeg.resize(numCourses);
        edges.resize(numCourses);
        for (vector<int> &info : prerequisites) {
            indeg[info[0]]++;
            edges[info[1]].emplace_back(info[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) { q.emplace(i); }
        }

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int u = q.front();
                q.pop();
                res.emplace_back(u);
                for (int &v : edges[u]) {
                    indeg[v]--;
                    if (indeg[v] == 0) { q.emplace(v); }
                }
            }
        }
        if (res.size() == numCourses) {
            return res;
        } else {
            return {};
        }
    }
};
// @lc code=end

int main() {
    //
    return 0;
}