/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        /* 从根节点组成的最小高度树
        把树当做图看待，从边缘(度=1)向内部广度优先搜索，
        则最后一轮遍历的节点(深度最深的节点)可以将整个图二分
        那么以他们为根的树高度最低
         */
        if (n == 1) return {0};
        queue<int> q; // bfs队列
        int degree[n];
        unordered_map<int, vector<int>> mp; //邻接表
        memset(degree, 0, sizeof(degree));
        // 找到度=1的节点
        for (auto &v : edges) {
            ++degree[v[0]];
            ++degree[v[1]];
            mp[v[0]].emplace_back(v[1]);
            mp[v[1]].emplace_back(v[0]);
        }
        // 度=1的节点入栈
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) { q.emplace(i); }
        }
        vector<int> res;
        while (!q.empty()) {
            res.clear();
            int sz = q.size();
            while (sz--) {
                int r = q.front();
                q.pop();
                res.emplace_back(r);
                degree[r]--;
                // 加入r的叶子节点
                for (auto j : mp[r]) {
                    degree[j]--;
                    if (degree[j] == 1) { q.emplace(j); }
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}