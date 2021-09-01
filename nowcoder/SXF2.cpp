#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int n, m;
    cin >> n >> m;
    int mat[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { cin >> mat[i][j]; }
    }

    int dp[n][m];
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        if (mat[i][0] == 1)
            dp[i][0] = 0;
        else if (dp[i - 1][0] == 0)
            dp[i][0] = 0;
        else {
            dp[i][0] = 1;
        }
    }
    for (int j = 1; j < m; j++) {
        if (mat[0][j] == 1)
            dp[0][j] = 0;
        else if (dp[0][j - 1] == 0)
            dp[0][j] = 0;
        else
            dp[0][j] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = 0;
            if (mat[i][j] != 1) dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            // if (mat[i][j] == 1)
            // dp[i][j] = 0;
            // else if (dp[i - 1][j] != 0) {
            // dp[i][j] += dp[i - 1][j];
            // } else if (dp[i][j - 1] != 0) {
            // dp[i][j] += dp[i][j - 1];
            // }
        }
    }
    // for (int i = 0; i < n; i++) {
    // for (int j = 0; j < m; j++) { printf("%5d ", dp[i][j]); }
    // cout << endl;
    // }
    cout << dp[n - 1][m - 1];
    return 0;
}