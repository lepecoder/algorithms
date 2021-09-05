#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int T;
    cin >> T;
    long long int maxn = 1000000000000000;
    int maxedge = 22360681;

    while (T--) {
        long long int n;
        cin >> n;
        if (n < 4) {
            cout << 0 << endl;
            continue;
        }
        int l = 1, r = maxedge;
        while (l < r) {
            int m = l + (r - l) / 2;
            long long int t = m * (4ll) + m * (2ll * (m - 1ll));
            if (t == n) {
                l = m;
                break;
            } else if (t < n) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        // 现在边长是l，向上加小木块
        long long int m = l * (4ll) + l * (2ll * (l - 1ll)); // 现在的木棍数量
        if (m > n) {
            l--;
            m = l * (4ll) + l * (2ll * (l - 1ll)); // 现在的木棍数量
        }
        long long int res = l * l; // 现在的正方形个数

        if (m + 3 + 2 * (l - 1) > n) {
            int t = 0;
            n = n - m;
            if (n >= 3) { t = t + (n - 3) / 2 + 1; }
            res += t;
        } else {
            int t = 0;
            t += l;
            n = n - m - 3 - 2 * (l - 1);
            if (n >= 3) { t = t + (n - 3) / 2 + 1; }
            res += t;
        }
        cout << res << endl;
    }
    return 0;
}