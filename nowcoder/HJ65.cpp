#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    string a, b;
    while (cin >> a >> b) {
        if (a.size() > b.size()) {
            swap(a, b); // 保持a是较短序列
        }
        int n = a.size(), m = b.size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    if (dp[i + 1][j + 1] > res) {
                        res = dp[i + 1][j + 1];
                        idx = i + 1;
                    }
                }
            }
        }
        for (int i = idx - res; i < idx; i++) { cout << a[i]; }
    }
    return 0;
}