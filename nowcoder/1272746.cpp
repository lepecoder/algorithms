#include <bits/stdc++.h>
using namespace std;

// 格式化显示时间
void show_time(int sec) {
    int h = 8;
    int m = 0;
    int s = 0;
    h += sec / 3600;
    m += sec / 60 % 60;
    s += sec % 60;
    char am[3] = "am";
    if (h > 12) {
        am[0] = 'p';
        h -= 12;
    }
    printf("%02d:%02d:%02d %s\n", h, m, s, am);
}

int main() {
    int _IO = []() {
        std::ios::sync_with_stdio(0);
        cin.tie(0); // cout.tie(0);
        return 0;
    }();
    //
    int T; // 测试用例
    int n;
    int a[2020];
    int b[2020];
    int dp[2020];
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) { cin >> a[i]; }
        for (int i = 2; i <= n; i++) { cin >> b[i]; }
        dp[0] = 0;
        dp[1] = a[1];
        for (int i = 2; i <= n; i++) { dp[i] = min(a[i] + dp[i - 1], b[i] + dp[i - 2]); }
        // cout << dp[n] << endl;
        show_time(dp[n]);
    }
    return 0;
}