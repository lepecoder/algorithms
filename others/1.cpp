#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int _IO = []() {
        std::ios::sync_with_stdio(0);
        cin.tie(0); // cout.tie(0);
        return 0;
    }();
    int n;
    cin >> n;
    vector<vector<int>> v;
    v.reserve(n + 1);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.emplace_back(vector<int>{a, b});
    }
    // for (auto &x : v) { cout << x[0] << ',' << x[1] << endl; }
    int res = 0;

    unordered_set<int> st1;
    unordered_set<int> st_1;
    for (int i = 0; i < n; i++) {
        vector<int> x = v[i];
        if (st1.count(i) == 0) { //没有被斜率1记录过
            int temp_count = 1;

            for (int j = i + 1; j < n; j++) {
                vector<int> y = v[j];
                if ((x[0] - y[0]) == (x[1] - y[1])) { // 斜率1
                    ++temp_count;
                    st1.emplace(j);
                }
            }
            int t = temp_count * (temp_count - 1) / 2;
            res += t;
        }
        if (st_1.count(i) == 0) { //没有被斜率-1记录过
            int temp_count = 1;
            for (int j = i + 1; j < n; j++) {
                vector<int> y = v[j];
                if ((x[0] - y[0]) == (y[1] - x[1])) { //斜率-1
                    ++temp_count;
                    st_1.emplace(j);
                }
            }
            int t = temp_count * (temp_count - 1) / 2;
            res += t;
        }
    }
    cout << res;

    return 0;
}