#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;

int main() {
    //
    int n, k;
    cin >> n >> k;
    int mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { cin >> mat[i][j]; }
    }

    int i = 0, j = 0;
    int ti = 0, tj = 0;
    while (i < n) {
        j = 0;
        tj = 0;
        while (j < n) {
            cout << mat[i][j] << ' ';
            tj++;
            if (tj == k) {
                j++;
                tj = 0;
            }
        }
        cout << endl;
        ti++;
        if (ti == k) {
            i++;
            ti = 0;
        }
    }

    return 0;
}