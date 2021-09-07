// #include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
typedef long long ll;
struct pair_hash {
    // template <typename t1, typename t2>
    hash<int> hint;
    int operator()(pair<int, int> const &p) const {
        int h1 = hint(p.first);
        int h2 = hint(p.second);
        return h1 ^ h2;
    }
};

struct pair_hash2 {
    template <class T1, class T2> std::size_t operator()(std::pair<T1, T2> const &pair) const {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    // map<pair<int, int>, int> mp;
    unordered_map<pair<int, int>, int, pair_hash> mp;
    // unordered_map<pair<int, int>, int,
    //               [&](pair<int, int> const &p1, pair<int, int> const &p2) {
    //                   std::size_t h1 = std::hash<int>()(pair.first);
    //                   std::size_t h2 = std::hash<int>()(pair.second);
    //                   return h1 ^ h2;
    //               }>
    //     mp;
    // __gnu_pbds::gp_hash_table<pair<int, int>, int> mp;
    int x, y;
    for (int i = 0; i < n; i++) {
        x = a[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            y = a[j];
            int gc = __gcd(x, y);
            // x /= gc;
            // y /= gc;
            mp[{x / gc, y / gc}]++;
        }
    }
    int res = 1;
    for (auto &p : mp) { res = max(res, p.second); }
    cout << res;

    return 0;
}