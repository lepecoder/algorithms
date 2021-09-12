#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    bool *vis;
    bool res;
    void dfs(int x, int target, vector<vector<int>> &edge) {
        if (vis[x] == true) return;
        if (x == target) res = true;
        vis[x] = true;
        for (int &v : edge[x]) { dfs(v, target, edge); }
    }
    bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start, int target) {
        vis = new bool[n];
        res = false;
        memset(vis, false, sizeof(bool) * n);
        vector<vector<int>> edge(n, vector<int>());
        for (vector<int> &e : graph) { edge[e[0]].emplace_back(e[1]); }
        dfs(start, target, edge);
        return res;
    }
};
int main() {
    //
    return 0;
}