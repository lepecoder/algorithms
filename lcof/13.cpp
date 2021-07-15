#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int res = 0;
    bool vis[101][101];
    int m, n, k;
    int dir[5] = {0, 1, 0, -1, 0};
    int check(int i, int j) {
        int res = 0;
        while (i) {
            res += i % 10;
            i /= 10;
        }
        while (j) {
            res += j % 10;
            j /= 10;
        }
        return res;
    }
    void dfs(int i, int j) {
        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        if (check(i, j) > k) return;
        if (vis[i][j] == true) return;
        vis[i][j] = true;
        res++;
        for (int k = 0; k < 4; k++) {
            int di = i + dir[k];
            int dj = j + dir[k + 1];
            dfs(di, dj);
        }
    }
    int movingCount(int m, int n, int k) {
        memset(vis, false, sizeof(vis));
        this->m = m;
        this->n = n;
        this->k = k;
        dfs(0, 0);
        return res;
    }
};
int main() {
    //
    Solution so;
    int a = so.check(32, 22);
    cout << a;
    return 0;
}