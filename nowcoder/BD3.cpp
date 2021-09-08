#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;
int res1, res2;
void rever(string &s, int r) {
    // cout << "reverse pre " << r + 1 << "  ";
    if (r == 0) return;
    int l = 0;
    while (l < r) { swap(s[l++], s[r--]); }
    res1++;
}
void rever2(string &s, int r) {
    // cout << "reverse pre " << r + 1 << "  ";
    if (r == 0) return;
    int l = 0;
    while (l < r) { swap(s[l++], s[r--]); }
    res2++;
}
int main() {
    //
    int n, q;
    string s;
    cin >> n >> q;
    while (q--) {
        cin >> s;
        string ori(s);
        res1 = 0;
        res2 = 0;
        string s1(s);
        // cout << "begin: " << s << endl;
        sort(s1.begin(), s1.end());
        for (int r = n - 1; r > 0; r--) {
            if (s[r] == s1[r]) continue;
            for (int i = 0; i < r; i++) {
                if (s[i] == s1[r]) {
                    rever(s, i);
                    // cout << s << endl;
                    break;
                }
            }
            rever(s, r);
            // cout << s << endl;
        }
        // cout << res1 << endl;
        sort(s1.begin(), s1.end(), greater<char>());
        // cout << "-----------\n";
        s = ori;
        for (int r = n - 1; r > 0; r--) {
            if (s[r] == s1[r]) continue;
            for (int i = 0; i < r; i++) {
                if (s[i] == s1[r]) {
                    rever2(s, i);
                    // cout << s << endl;
                    break;
                }
            }
            rever2(s, r);
            // cout << s << endl;
        }
        res2++;
        // cout << res2 << endl;
        cout << min(res1, res2) << endl;
    }
    return 0;
}