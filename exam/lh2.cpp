#include <bits/stdc++.h>
using namespace std;
#define ll long long

int R, n;
inline double dis(int x, int y, pair<int, int> &p) { return pow(x - p.first, 2) + pow(y - p.second, 2); }
int count(int x, int y, vector<pair<int, int>> &mo) {
    int res = 0;
    for (pair<int, int> &p : mo) {
        if (dis(x, y, p) <= R * R) { res++; }
    }
    return res;
}

int main() {
    //
    cin >> R >> n;
    // pair<int,int> mo[n];
    vector<pair<int, int>> mo(n);
    int max_x = 0, max_y = 0;
    for (int i = 0; i < n; i++) {
        cin >> mo[i].first >> mo[i].second;
        max_x = max(max_x, mo[i].first);
        max_y = max(max_y, mo[i].second);
    }
    max_x += R;
    max_y += R;
    pair<int, int> res;
    int max_v = 0;
    for (int x = 1; x <= max_x; x++) {
        for (int y = 1; y <= max_y; y++) {
            int t = count(x, y, mo);
            if (max_v <= t) {
                max_v = t;
                res.first = x;
                res.second = y;
                // res = {x, y};
            }
        }
    }
    cout << res.first << ' ' << res.second;

    return 0;
}