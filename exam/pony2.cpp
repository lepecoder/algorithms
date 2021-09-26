#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    // cout << endl;
int main() {
    //
    string s;
    cin >> s;
    unordered_map<char, vector<int>> mp;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (mp.count(c) == 0) mp[c].emplace_back(-1);
        mp[c].emplace_back(i);
    }
    int res = (n + 1) / 2;
    for (auto &p : mp) {
        vector<int> &v = p.second;
        v.emplace_back(n);
        // cout << p.first << '-';
        // show(v, 0, v.size());
        // 找到v的最大间隔
        int t = 0;
        for (int i = 1; i < v.size(); i++) { t = max(t, v[i] - v[i - 1]); }
        // cout << '+' << t << endl;

        res = min(res, t);
    }
    cout << res;

    return 0;
}