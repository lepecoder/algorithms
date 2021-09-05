/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */
#include <bits/extc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        // times[i] = <ui, vi, wi>  存储边的权重
        // 有n个节点，从节点k发出信号，需要多久才能让所有节点都收到信号
        vector<vector<pair<int, int>>> g(n); // g[u] <v, weight>
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].emplace_back(y, t[2]);
        }
        vector<int> dis(n, 0x3f3f3f3f);
        dis[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q; // <time, u>
        q.emplace(0, k - 1);
        bool vis[n];
        memset(vis, false, sizeof(vis));
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int time = p.first, x = p.second;
            if (vis[x] == true) continue;
            vis[x] = true;
            if (dis[x] < time) continue;
            for (auto &e : g[x]) {
                int y = e.first, d = dis[x] + e.second;
                if (d < dis[y]) {
                    dis[y] = d;
                    q.emplace(d, y);
                }
            }
        }
        int ans = *max_element(dis.begin(), dis.end());
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}