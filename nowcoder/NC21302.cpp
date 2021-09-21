#include <bits/stdc++.h>
using namespace std;
#define ll long long
int res = 0;
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;
void dfs(string str, int idx, int k, vector<char> &path) {
    if (idx == str.size()) {
        // show(path, 0, path.size());
        if (k % 3 == 0) { res++; }
        return;
    }
    dfs(str, idx + 1, k, path);
    path.emplace_back(str[idx]);
    dfs(str, idx + 1, k + str[idx] - '0', path);
    path.pop_back();
}
int main() {
    //
    string str;
    cin >> str;
    vector<char> path;
    dfs(str, 0, 0, path);
    cout << res - 1;
    return 0;
}