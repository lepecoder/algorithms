#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << '\n';                                                                                                        \
    cout << endl;
int n;
vector<string> res;
string s;
void dfs(string &path, int idx, bool vis[]) {
    if (idx == n) {
        res.emplace_back(path);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i] == true || i > 0 && s[i] == s[i - 1] && vis[i - 1] == true) continue;
        path[idx] = s[i];
        vis[i] = true;
        dfs(path, idx + 1, vis);
        vis[i] = false;
    }
}

int main() {
    //
    cin >> s;
    n = s.size();
    string path(s);
    sort(s.begin(), s.end());
    bool vis[n];
    memset(vis, false, sizeof(vis));
    dfs(path, 0, vis);
    // show(res, 0, res.size());
    for (string &x : res) { cout << x << endl; }
    return 0;
}