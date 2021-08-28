/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> edges;
        vector<int> indeg;
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (auto &info : prerequisites) {
            edges[info[1]].emplace_back(info[0]);
            indeg[info[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) q.emplace(i);
        }
        int vis = 0;
        while (!q.empty()) {
            vis++;
            int u = q.front();
            q.pop();
            for (int &v : edges[u]) {
                indeg[v]--;
                if (indeg[v] == 0) { q.emplace(v); }
            }
        }
        return vis == numCourses;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}