#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();

inline bool check(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.first == p2.first || p1.first == p2.second || p1.second == p2.first || p1.second == p2.second) { return false; }
    return true;
}

int main() {
    int n;
    ll res = 0;
    cin >> n;
    int a[n];
    res = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> v(n * n);
    int k = 0;
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            v[k] = a[i] ^ a[j];
            mp[k] = {i, j};
            k++;
        }
    }
    int x, y;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (mp[i].second >= mp[j].first) continue;
            if (check(mp[i], mp[j])) {
                // 没有重复
                int t = v[i] ^ v[j];
                res += t;
                if (res >= MOD) res -= MOD;
            }
        }
    }

    // vector<int> path;
    // dfs(a, 0, path);
    cout << res;

    return 0;
}