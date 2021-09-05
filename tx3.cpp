#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    map<pair<int, int>, int> mp;
    int x, y;
    for (int i = 0; i < n; i++) {
        x = a[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            y = a[j];
            int gc = __gcd(x, y);
            // x /= gc;
            // y /= gc;
            mp[{x / gc, y / gc}]++;
        }
    }
    int res = 1;
    for (auto &p : mp) { res = max(res, p.second); }
    cout << res;

    return 0;
}