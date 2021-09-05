#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; // 公交站牌数
    int m; // 公交线路数
    int k, t;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>{});
    for (int i = 0; i < n; i++) {
        cin >> k;
        while (k--) {
            cin >> t;
            vec[i].emplace_back(t - 1);
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    // for (int i = )

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { cout << dp[i][j] << ' '; }
        cout << endl;
    }

    return 0;
}