#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int n; //教授人数
    int m; //认可关系
    int a, b;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>{});
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].emplace_back(b);
    }

    return 0;
}