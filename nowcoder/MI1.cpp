#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int m, n;
    string line;
    getline(cin, line);
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == 'm' || line[i] == 'n' || line[i] == '=' || line[i] == ',') line[i] = ' ';
    }
    istringstream ss(line);
    ss >> m >> n;
    // cout << m << ' ' << n << endl;
    int a[m + n]; // m
    int b[n];
    char c;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        if (i < m - 1) cin >> c;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (i < n - 1) cin >> c;
    }
    // 由大到小合并
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (k >= 0) {
        if (i < 0)
            a[k--] = b[j--];
        else if (j < 0)
            a[k--] = a[i--];
        else {
            if (a[i] > b[j])
                a[k--] = a[i--];
            else
                a[k--] = b[j--];
        }
    }
    for (int i = 0; i < m + n; i++) { cout << a[i] << ' '; }

    return 0;
}