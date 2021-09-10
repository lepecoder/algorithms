#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    int house[22][3]; // house[i][0] 第i幢房子涂成红色的成本
    char c;
    int n = 1;
    cin >> house[0][0] >> house[0][1] >> house[0][2];
    while (cin >> c) {
        cin >> house[n][0] >> house[n][1] >> house[n][2];
        n++;
    }
    int dp[22][3]; // dp[i][0] 表示涂了前i幢房子，而且第i幢房子涂红色的最小成本
    dp[0][0] = house[0][0];
    dp[0][1] = house[0][1];
    dp[0][2] = house[0][2];
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
    }
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));

    return 0;
}