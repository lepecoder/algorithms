#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    map<int, int> mp;
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        mp[a] += b;
    }
    for (auto &x : mp) { cout << x.first << ' ' << x.second << endl; }
    return 0;
}