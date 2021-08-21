#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int n, m;
    vector<int> price;
    price.reserve(1010);
    unordered_map<string, int> mp;
    int max_v, min_v, t;
    string name;
    while (cin >> n >> m) {
        mp.clear();
        price.clear();
        for (int i = 0; i < n; i++) {
            cin >> t;
            price.emplace_back(t);
        }
        sort(price.begin(), price.end());
        for (int i = 0; i < m; i++) {
            cin >> name;
            mp[name] += 1;
        }
        for (auto &p : mp) {}
    }
    return 0;
}