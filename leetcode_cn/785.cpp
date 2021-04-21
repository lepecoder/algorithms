/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        /* 判断二分图
        分别将边两侧的节点放入两个集合
        graph是邻接表
         */
        int n = graph.size();
        unordered_set<int> s1{0}, s2, visited;
        queue<int> q1, q2;
        q1.emplace(0);
        // 图可能是不连通的，因此必须有多个入口
        while (visited.size() < n) { // 集合二分表示遍历结束
            while (!q1.empty()) {
                int r = q1.front();
                visited.emplace(r);
                q1.pop();
                for (int &x : graph[r]) { // 找节点r另一端的点
                    if (s1.count(x)) {    // 如果另一个端在s1一定是错的
                        return false;
                    }
                    if (s2.count(x) == 0) { // 如果另一端不在s2，表示还没遍历过，加入s2
                        s2.emplace(x);
                        q2.emplace(x);
                    }
                }
            }
            while (!q2.empty()) {
                int r = q2.front();
                visited.emplace(r);
                q2.pop();
                for (int &x : graph[r]) {
                    if (s2.count(x)) { // 如果另一个端在s1一定是错的
                        return false;
                    }
                    if (s1.count(x) == 0) { // 如果另一端不在s2，表示还没遍历过，加入s2
                        s1.emplace(x);
                        q1.emplace(x);
                    }
                }
            }
            if (q1.empty()) {
                for (int i = 0; i < n; i++) {
                    if (visited.count(i) == 0) {
                        q1.emplace(i);
                        break;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> graph{{4, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 0}};
    Solution so;
    bool ans = so.isBipartite(graph);
    cout << ans;

    return 0;
}