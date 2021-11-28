#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<vector<int>> vec;
    int n, m, x;
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == ']' || s[i] == ',') { s[i] = ' '; }
        }
        istringstream line(s);
        vector<int> temp;
        while (line >> x) { temp.emplace_back(x); }
        vec.emplace_back(temp);
    }
    n = vec.size();
    m = vec[0].size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = 0;
            queue<pair<int, int>> q;
            q.emplace(i, j);
            while (!q.empty()) {
                auto curp = q.front();
                q.pop();
                if (curp.first < 0 || curp.first >= n || curp.second < 0 || curp.second >= m || vec[curp.first][curp.second] != 1) continue;
                cur++;
                vec[curp.first][curp.second] = 0;
                int di[5] = {0, 1, 0, -1, 0};
                for (int i = 0; i < 4; i++) {
                    int ni = curp.first + di[i];
                    int nj = curp.second + di[i + 1];
                    q.emplace(ni, nj);
                }
                res = max(res, cur);
            }
        }
    }
    cout << res;

    return 0;
}