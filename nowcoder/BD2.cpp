#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;

int main() {
    //
    int T;
    int n;
    cin >> T;
    int res = 0;
    int a, b;
    while (T--) {
        res = 0;
        cin >> n;
        for (a = 1; a < sqrt(n); a++) {
            if (n % a != 0) continue;
            b = n / a;
            if (__gcd(a, b) == 1) {
                // cout << a << ',' << b << endl;
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}