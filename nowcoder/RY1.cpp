#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    string line;
    vector<int> v;
    int t;
    v.reserve(60000);
    cin >> line;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            //
            line[i] = ' ';
        }
    }
    istringstream ss(line);
    while (ss >> t) { v.emplace_back(t); }
    int n = v.size();
    vector<vector<int>> res;
    int resn;
    bool bs[n]; // 是否输出
    memset(bs, false, sizeof(bs));
    int vis = 0;
    while (true) {
        if (vis == n) { break; }
        vector<int> res_v;
        for (int i = 0; i < n; i++) {
            if (bs[i] == true) continue;
            if (res_v.empty() || v[i] < res_v.back()) {
                res_v.emplace_back(v[i]);
                bs[i] = true;
            }
        }
        if (res_v.empty()) { break; }
        res.emplace_back(res_v);
    }
    cout << res.size() << endl;
    for (vector<int> &res_v : res) {
        for (int i = 0; i < res_v.size(); i++) {
            cout << res_v[i];
            if (i < res_v.size() - 1) {
                cout << ',';
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}