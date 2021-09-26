#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;
int n;
ll res = 0;

// void fun(vector<int> arr, int idx, int max_, int min_, bool bs) {
//     if (bs == true && idx == n) {
//         res += max_ + min_;
//         if (res >= MOD) res -= MOD;
//     }
//     if (idx >= n) return;
//     // no choice
//     fun(arr, idx + 1, max_, min_, bs);
//     // choice
//     max_ = max(max_, arr[idx]);
//     min_ = min(min_, arr[idx]);
//     fun(arr, idx + 1, max_, min_, true);
// }

int main() {
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int max_ = INT_MIN;
    int min_ = INT_MAX;
    vector<int> t;
    for (int mask = 0; mask < (1 << n); mask++) {
        max_ = INT_MIN;
        min_ = INT_MAX;
        // t.clear();
        bool bs = false;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                // t.push_back(arr[i]);
                bs = true;
                max_ = max(max_, arr[i]);
                min_ = min(min_, arr[i]);
            }
        }
        if (bs == false) continue;
        // if (t.empty()) cout << '.';
        // show(t, 0, t.size());
        res += max_ + min_;
        if (res >= MOD) res -= MOD;
    }

    // fun(arr, 0, max_, min_, false);
    cout << res;

    return 0;
}