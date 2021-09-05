#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int K;
int fun(int a[], int n, int m, int k, int idx) {
    if (m <= 0) return idx;
    if (k <= 0) {
        // 使用技能
        int ax = fun(a, n, m, K, idx + 1);
        // 不适用技能
        int bx = fun(a, n, m - a[idx], k - 1, idx + 1);
        return max(ax, bx);
    }
    // 不适用
    int ans = fun(a, n, m - a[idx], k - 1, idx + 1);
    return ans;
}

int main() {
    //
    int n, m;
    // m 初始血量、
    // k 冷却接下来k层
    cin >> n >> m >> K;
    int a[n];
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    int ans;
    ans = fun(a, n, m, K, 0);
    cout << ans;

    return 0;
}