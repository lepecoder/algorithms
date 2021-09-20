#include <bits/stdc++.h>
using namespace std;
#define ll long long

int fun(int x) {
    if (x < 38) return x;
    int y = x;
    while (y % 5 != 0) y++;
    if ((y - x) < 3) return y;
    return x;
}

int main() {
    //
    ll n;
    cin >> n;
    int x;
    while (n--) {
        cin >> x;
        cout << fun(x) << endl;
    }
    return 0;
}