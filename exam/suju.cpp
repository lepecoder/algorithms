#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // 算术教室
    int _IO = []() {
        std::ios::sync_with_stdio(0);
        cin.tie(0); // cout.tie(0);
        return 0;
    }();
    int n, m, x;
    cin >> n >> m >> x;
    unordered_set<int> st1, st2;
    st1.reserve(n);
    st2.reserve(m);
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        st1.emplace(t);
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        st2.emplace(t);
    }
    for (int e : st1) {
        if (st2.count(x - e)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}