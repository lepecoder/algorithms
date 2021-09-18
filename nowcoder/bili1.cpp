#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') s[i] = ' ';
    }
    istringstream line(s);
    int t;
    vector<int> a;
    while (line >> t) { a.emplace_back(t); }
    int n = a.size();
    cout << n << endl;
    for (int i = 0; i < n / 2; i++) {
        cout << a[i] << ',' << a[n - 1 - i];
        if (i < n / 2 - 1) { cout << ','; }
    }
    if (n % 2 == 1) { cout << ',' << a[n / 2]; }
    return 0;
}