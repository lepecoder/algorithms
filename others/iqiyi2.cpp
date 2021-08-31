#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    string line;
    int t;
    vector<int> v;
    vector<int> v1;
    while (getline(cin, line)) {
        v.clear();
        v1.clear();
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ',') { line[i] = ' '; }
        }
        istringstream stream(line);
        while (stream >> t) { v.emplace_back(t); }
        v1.emplace_back(v.front()); // 前后两个肯定是算波峰波谷的
        int n = v.size();
        for (int i = 1; i < n - 1; i++) {
            if (v[i] >= v[i - 1] && v[i] >= v[i + 1] || v[i] <= v[i - 1] && v[i] <= v[i + 1]) { v1.emplace_back(v[i]); }
        }
        v1.emplace_back(v.back());
        int res = 0;
        for (int i = 0; i < v1.size() - 1; i++) { res = max(res, abs(v1[i] - v1[i + 1])); }
        cout << res << endl;
        // for (int &x : v) { cout << x << ' '; }
        // cout << endl;
    }
    return 0;
}