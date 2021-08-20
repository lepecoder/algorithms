#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int m, n;
    int t;
    set<int> st;

    while (cin >> m >> n) {
        st.clear();
        while (m--) {
            cin >> t;
            st.emplace(t);
        }
        while (n--) {
            cin >> t;
            st.emplace(t);
        }
        for (auto &x : st) { cout << x << ' '; }
        cout << endl;
    }

    return 0;
}