#include <bits/stdc++.h>
using namespace std;
int divi(int n, int x) {
    int res = 0;
    while (n) {
        res += n % x;
        n /= x;
    }
    return res;
}
inline int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}
int main() {
    //
    int n;
    while (cin >> n) {
        if (n == 1) {
            cout << "1/1\n";
            continue;
        }
        // if (n==2)
        int res = 0;
        for (int i = 2; i < n; i++) { res += divi(n, i); }
        int t = gcd(res, n - 2);
        cout << res / t << '/' << (n - 2) / t << endl;
    }

    return 0;
}