#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 500001;

int main() {
    int n;
    cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) { cin >> arr[i].first >> arr[i].second; }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (res > n - i || res > n / 2) break;
        unordered_map<int, int> mp;
        for (int j = i + 1; j < n; j++) {
            int x = arr[i].first - arr[j].first;
            int y = arr[i].second - arr[j].second;
            if (x == 0) {
                y = 1;
            } else if (y == 0) {
                x = 1;
            } else {
                if (y < 0) {
                    x = -x;
                    y = -y;
                }
                int gcd = __gcd(abs(x), abs(y));
                x /= gcd;
                y /= gcd;
            }
            mp[y + x * maxn]++;
        }
        int maxnn = 0;
        // for (auto &[_, num] : mp) { maxnn = max(maxnn, num + 1); }
        for (auto &p : mp) {
            int num = p.second;
            maxnn = max(maxnn, num + 1);
        }
        res = max(res, maxnn);
    }
    cout << res;

    return 0;
}