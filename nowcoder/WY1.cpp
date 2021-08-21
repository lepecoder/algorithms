#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    vector<int> a;
    int t;
    while (cin >> t) { a.emplace_back(t); }
    int n = a.size() - 1;
    int M = a.back();
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] <= M) { res++; }
        }
    }
    cout << res;

    return 0;
}