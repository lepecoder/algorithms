#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    int T;
    int n;
    cin >> T;
    while (T--) {
        cin >> n;
        int res = 0;
        n /= 3;
        for (int x = 1; x < n - 1; x++) {
            int y = n - x;
            int count = y - 1;
            res += count;
        }
        cout << res << endl;
    }
    return 0;
}