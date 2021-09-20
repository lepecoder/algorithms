#include <bits/stdc++.h>
using namespace std;
int n;

// void bfs(int x, unordered_map<int,vector<int>> &mp, bool vis[], int times[]){ }
bool vis[11000];
int bfs(int x, unordered_map<int, vector<pair<int, int>>> &mp, vector<int> &next) {
    auto v = mp[x];
    int res = 0;
    if (x >= 0) vis[x] = true;
    for (pair<int, int> &t : v) {
        res = max(t.first, res);
        if (vis[t.second] == false) { next.emplace_back(t.second); }
    }
    return res;
}

int main() {
    // 拓扑排序
    // 广度优先搜索
    memset(vis, true, sizeof(vis));
    cin >> n;
    for (int i = 0; i < n; i++) { vis[i] = false; }
    int pre;
    int time;
    unordered_map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        cin >> pre >> time;
        if (mp.count(pre) == 0) {
            vector<pair<int, int>> v;
            v.emplace_back(time, i);
            mp[pre] = v;
        } else {
            mp[pre].emplace_back(time, i);
        }
    }
    int res = 0;
    // bool vis[n];
    // memset(vis,false,sizeof(vis));
    // int times[n];
    queue<int> q;
    q.emplace(-1);
    while (!q.empty()) {
        int count = q.size();
        int time = 0;
        vector<int> next;
        while (count--) {
            int task = q.front();
            q.pop();
            time = max(time, bfs(task, mp, next));
            for (int &x : next) { q.emplace(x); }
        }
        res += time;
    }
    cout << res;

    return 0;
}