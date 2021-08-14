#include <bits/stdc++.h>
using namespace std;

int horse[2];
int m, n, x, y;
// int so(int horse[2], int m, int n) {}
bool check(int x, int y) {
    // 检查点是否在坐标内
    if (x >= 0 && x <= m && y >= 0 && y <= n) {
        return true;
    } else
        return false;
}

int main() {

    cin >> m >> n >> horse[0] >> horse[1];
    // control points
    // vector<pair<int, int>> c_points;
    set<pair<int, int>> c_points;
    c_points.emplace(horse[0], horse[1]);
    int dir1[5] = {-1, 2, 1, -2, -1};
    int dir2[5] = {1, 2, -1, -2, 1};
    for (int i = 0; i < 4; i++) {
        x = horse[0] + dir1[i];
        y = horse[1] + dir1[i + 1];
        if (check(x, y)) { c_points.emplace(x, y); }
        x = horse[0] + dir2[i];
        y = horse[1] + dir2[i + 1];
        if (check(x, y)) { c_points.emplace(x, y); }
    }
    long long int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (c_points.count(pair<int, int>(i, j))) {
                dp[i][j] = 0;
            } else {
                if (i > 0) { dp[i][j] += dp[i - 1][j]; }
                if (j > 0) { dp[i][j] += dp[i][j - 1]; }
            }
        }
    }
    cout << dp[m][n];
    return 0;
}
