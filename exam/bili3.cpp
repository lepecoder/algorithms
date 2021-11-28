#include <bits/stdc++.h>
using namespace std;
#define ll long long

int find(int fa[], int x) {
    if (fa[x] == x) return x;
    fa[x] = find(fa, fa[x]);
    return fa[x];
}

void merge(int fa[], int x, int y) {
    int a = find(fa, x);
    int b = find(fa, y);
    fa[a] = b;
}

int main() {
    //
    int n;
    int ai;
    int m;
    char c;
    int x, y;
    cin >> n >> ai >> m;
    int fa[n];
    for (int i = 0; i < n; i++) { fa[i] = i; }
    int res = -1;
    for (int i = 0; i < m; i++) {
        cin >> x >> c >> y;
        if (x == ai || y == ai) res--;
        merge(fa, x, y);
    }
    int faai = find(fa, ai);
    for (int i = 0; i < n; i++) {
        if (find(fa, i) == faai) res++;
    }
    cout << res;
    return 0;
}