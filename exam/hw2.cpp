#include <bits/stdc++.h>
using namespace std;

int n, m;

class Solution {
  public:
    int mat[20][20];
    int dp[20][20]; // dp[i][j] 到i,j的最段时间，-1表示不可达
    bool bp[20][20];
};

// int mat[20][20];
// bool dp[20][20][110]; // dp[i][j][t]是否可以经过>=t时刻到达i,j

int main() {
    //
    Solution so;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { cin >> so.mat[i][j]; }
    }
    // 下标从1开始
    memset(so.bp, false, sizeof(so.bp));
    memset(so.dp, -1, sizeof(so.dp));
    so.dp[1][1] = 0;
    for (int i = 0; i <= n; i++) so.bp[i][0] = true;
    for (int j = 0; j <= m; j++) so.bp[0][j] = true;
    so.bp[1][1] = true;
    for (int i = 2; i <= n; i++) {
        if (so.dp[i - 1][1] == -1)
            so.dp[i][1] = -1;
        else {
            so.dp[i][1] = so.dp[i - 1][1] + 1;
            if (so.dp[i][1] > so.mat[i][1]) { so.dp[i][1] = -1; }
        }
    }
    for (int j = 2; j <= m; j++) {
        if (so.dp[1][j - 1] == -1)
            so.dp[1][j] = -1;
        else {
            so.dp[1][j] = so.dp[1][j - 1] + 1;
            if (so.dp[1][j] > so.mat[1][j]) { so.dp[1][j] = -1; }
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            so.dp[i][j] = INT_MAX;
            if (so.dp[i - 1][j] != -1) { so.dp[i][j] = min(so.dp[i][j], so.dp[i - 1][j] + 1); }
            if (so.dp[i][j - 1] != -1) { so.dp[i][j] = min(so.dp[i][j], so.dp[i][j - 1] + 1); }
            if (so.dp[i][j] > so.mat[i][j]) { so.dp[i][j] = -1; }
        }
    }
    cout << so.dp[n][m];
    // for (int i = 1; i <= n; i++) {
    // for (int j = 1; j <= m; j++) { cout << so.dp[i][j] << ' '; }
    // cout << endl;
    // }
    // cout << so.fun(n, m);

    return 0;
}