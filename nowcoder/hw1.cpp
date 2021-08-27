#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int n, m;
    int mat[13][13];
    int dp[13][13][13][13];  // dp[i][j][x][y] 从i,j -> x,y 矩形区域面积
    bool bp[13][13][13][13]; // bp[i][j][x][y] 表示这块面积还没有被计算过

    int fun(int i, int j, int x, int y) {
        if (i >= x || j >= y) return 0;
        if (bp[i][j][x][y] == true) return dp[i][j][x][y];
        bp[i][j][x][y] = true;
        if (x - 1 > i) {
            dp[i][j][x][y] = fun(i, j, x - 1, y) + fun(x - 1, j, x, y);
            return dp[i][j][x][y];
        }
        if (y - 1 > j) {
            dp[i][j][x][y] = fun(i, j, x, y - 1) + fun(i, y - 1, x, y);
            return dp[i][j][x][y];
        }
        return 0;
    }
};

int main() {
    //
    Solution so;
    cin >> so.n >> so.m;
    for (int i = 0; i < so.n; i++) {
        for (int j = 0; j < so.m; j++) { cin >> so.mat[i][j]; }
    }
    memset(so.dp, 0, sizeof(so.dp));
    memset(so.bp, false, sizeof(so.bp));

    // 赋值一个方格
    for (int i = 0; i < so.n; i++) {
        for (int j = 0; j < so.m; j++) {
            so.bp[i][j][i + 1][j + 1] = true;
            so.dp[i][j][i + 1][j + 1] = so.mat[i][j];
        }
    }
    int res = INT_MIN;
    int t;
    for (int i = 0; i < so.n; i++) {
        for (int j = 0; j < so.m; j++) {
            for (int x = i + 1; x <= so.n; x++) {
                for (int y = j + 1; y <= so.m; y++) {
                    t = so.fun(i, j, x, y);
                    res = max(res, t);
                }
            }
        }
    }
    cout << res;
    // cout << endl;

    return 0;
}