#include <bits/stdc++.h>
using namespace std;

int main() {
    // ab串
    int n;
    const int MOD = 998244353;
    cin >> n;
    if (n <= 2) return pow(2, n);
    long long aa = 1, ab = 1, ba = 1, bb = 1;
    for (int i = 3; i <= n; i++) {
        // 补a
        long long naa = aa + ba;
        long long nba = bb;
        // 补b
        long long nab = aa;
        long long nbb = ab + bb;
        aa = naa % MOD;
        ba = nba % MOD;
        ab = nab % MOD;
        bb = nbb % MOD;
    }
    long long res = (aa + ba + ab + bb) % MOD;
    cout << res << endl;
    cout << LONG_LONG_MAX;

    return 0;
}