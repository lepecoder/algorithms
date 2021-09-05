#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    //
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    // 必须是一半的人在足球队，另一半人在篮球队，而且两队之和最大
    vector<pair<int, int>> vec;
    vec.reserve(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        c[i] = a[i] - b[i];
        vec.emplace_back(c[i], i);
    }
    sort(vec.begin(), vec.end());
    ll res = 0, idx;
    for (int i = 0; i < n / 2; i++) {
        idx = vec[i].second;
        res += b[idx];
    }
    for (int i = n / 2; i < n; i++) {
        idx = vec[i].second;
        res += a[idx];
    }
    cout << res;

    return 0;
}