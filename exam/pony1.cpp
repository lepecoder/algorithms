#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll res = 0;
    for (int i = 1; i < n; i++) {
        ll t = a[i] - a[i - 1];
        res += t * t;
    }
    cout << res;
    return 0;
}