class Solution {
  public:
    int res = 0;
    void dfs(map<int, vector<int>> &mp, int a, int k, int n) {
        if (k == 0) {
            if (a == n - 1) ++res;
        } else {
            auto v = mp[a];
            for (int &x : v) { dfs(mp, x, k - 1, n); }
        }
    }
    int numWays(int n, vector<vector<int>> &relation, int k) {
        map<int, vector<int>> mp; // 图的邻接表
        for (auto &rel : relation) {
            if (mp.count(rel[0]) == 0) {
                mp[rel[0]] = {rel[1]};
            } else {
                mp[rel[0]].push_back(rel[1]);
            }
        }
        dfs(mp, 0, k, n);
        return res;
    }
};
