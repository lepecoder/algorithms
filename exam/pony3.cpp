#include <bits/stdc++.h>
using namespace std;
#define ll long long

int find(int fa[], int x) {
    if (fa[x] == x)
        return x;
    else {
        fa[x] = find(fa, fa[x]);
        return fa[x];
    }
}

void merge(int fa[], int x, int y) { fa[find(fa, x)] = find(fa, y); }

int main() {
    int n, m;
    cin >> n >> m;
    int cost[n + 1];
    for (int i = 1; i <= n; i++) cin >> cost[i];
    int fa[n + 1];
    for (int i = 1; i <= n; i++) { fa[i] = i; }
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        merge(fa, a, b);
    }
    unordered_map<int, int> mp; // mp[x]=y, 传给x的最小代价是y
    int x, y;
    for (int i = 1; i <= n; i++) {
        x = find(fa, i);
        y = cost[i];
        if (mp.count(x) == 0) {
            mp[x] = y;
        } else {
            mp[x] = min(mp[x], y);
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) { res += mp[i]; }
    cout << res;

    return 0;
}