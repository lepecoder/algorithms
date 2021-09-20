#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    //
    ull a, b, c;
    cin >> a >> b >> c;
    ull xbegin = sqrt(a);
    while (xbegin * xbegin < a) xbegin++;
    ull xend = sqrt(b);
    while (pow(xend + 1, 2) <= b) xend++;
    ull ybegin = pow(a, 1.0 / 3.0);
    while (ybegin * ybegin * ybegin < a) ybegin++;
    ull yend = pow(b, 1.0 / 3.0);
    while (pow(yend + 1, 3) <= b) yend++;
    // cout << xbegin << ',' << xend << endl;
    // cout << ybegin << ',' << yend << endl;
    ull res = 0;
    for (long long x = xbegin; x <= xend; x++) {
        ull tx = x * x;
        if (tx > b || tx < a) continue;
        for (long long y = ybegin; y <= yend; y++) {
            ull ty = y * y * y;
            if (ty > b || ty < a) continue;
            if (tx > ty && tx - ty <= c || tx < ty && ty - tx <= c) { res++; }
            // if (tx-ty <= c) { res++; }
        }
    }
    cout << res;
    return 0;
}