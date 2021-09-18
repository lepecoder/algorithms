#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    int n, m;
    cin >> n >> m;
    int t = n * m;
    int left[t + 1];
    int up[t + 1];
    int right[t + 1]; // right[x]=y  x的右边是y
    int down[t + 1];  // down[x]=y  x的下面是y
    int a, b, c, d;
    int x;
    int start;
    for (int i = 1; i <= t; i++) {
        cin >> x >> a >> b >> c >> d;
        left[x] = a;
        up[x] = b;
        right[x] = c;
        down[x] = d;
        if (a == 0 && b == 0) { start = x; }
    }
    // vector<vector<int>> res(n,vector<int>(m));
    int res[n][m];
    res[0][0] = start;
    for (int j = 1; j < m; j++) { res[0][j] = right[res[0][j - 1]]; }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) { res[i][j] = down[res[i - 1][j]]; }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { cout << res[i][j] << ' '; }
        cout << endl;
    }

    return 0;
}