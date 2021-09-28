#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    int m, n;
    cin >> m >> n;
    vector<pair<double, double>> v; // v结束时间，开始时间
    int t = m + n;
    v.reserve(t);
    int a, b, c, d;
    char cc;
    for (int i = 0; i < t; i++) {
        cin >> a >> cc >> b >> cc >> c >> cc >> d;
        double start = a + b / 60.0;
        double end = c + d / 60.0;
        v.emplace_back(end, start);
    }
    sort(v.begin(), v.end());
    int res = 0;
    double pre = 0; // 上一个的结束时间
    for (auto &p : v) {
        if (p.second < pre) continue; // 当前的开始时间在上一个结束之前
        res++;
        pre = p.first;
    }
    cout << res;

    return 0;
}