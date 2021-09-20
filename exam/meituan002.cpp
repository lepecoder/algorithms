#include <bits/stdc++.h>
using namespace std;
int n;
int *w;
int *s;
int t;

int main() {

    cin >> n;
    w = new int[n + 1];
    s = new int[n + 1];
    for (int i = 1; i <= n; i++) { cin >> w[i]; }
    for (int i = 1; i <= n; i++) { cin >> s[i]; }
    int sum = accumulate(w + 1, w + n + 1, 0);
    // cout << sum << endl;
    int pre[n + 1]; // 前n项和
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = w[i] + pre[i - 1];
        cout << pre[i] << ' ';
    }

    return 0;
}