#include <bits/stdc++.h>
using namespace std;

int m, n;
int dir[5] = {0, 1, 0, -1, 0};
int mat[22][22];
int fun(int pi, int pj) {
    vector<vector<int>> dp(m, vector<int>(n, 100000));
    dp[pi][pj] = 0;
    stack<pair<int, int>> stk;
    stk.emplace(pi, pj);
    while (!stk.empty()) {
        int count = stk.size();
        while (count--) {
            pair<int, int> p = stk.top();
            stk.pop();
            /* 四个方向遍历 */
            for (int k = 0; k < 4; k++) {
                int ni = p.first + dir[k];
                int nj = p.second + dir[k + 1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (dp[ni][nj] > dp[p.first][p.second] + mat[ni][nj]) { // 需要更新
                        dp[ni][nj] = dp[p.first][p.second] + mat[ni][nj];
                        stk.emplace(ni, nj);
                    }
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) { res = max(res, dp[i][j]); }
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    return res;
}

int main() {
    cin >> m >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 0) { v.emplace_back(i, j); }
        }
    }
    vector<int> res;
    for (pair<int, int> &p : v) {
        int t = fun(p.first, p.second);
        res.emplace_back(t);
    }
    cout << *max_element(res.begin(), res.end());
    return 0;
}