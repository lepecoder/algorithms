#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int count0 = 0;
int count1 = 0;
inline int gcd(int a, int b) {
    if (b == 0) return a;
    if (a % b == 0)
        return b;
    else
        return (b, a % b);
}
bool check(int n, int k) {
    // 检查字符串的前n个字符能不能分成k组
    if (k == 1) return true;
    if (n % k != 0) return false;
    if (count1 == 0 || count0 == 0) return true;
    if (count1 % k != 0 || count0 % k != 0) return false;
    int t = n / k; // 每一组
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            c0++;
        } else {
            c1++;
        }
        if ((i + 1) % t == 0) {
            if (c0 == count0 / k && c1 == count1 / k) {
                c0 = 0;
                c1 = 0;
            } else {
                return false;
            }
        }
    }
    return true;
}
int main() {
    //
    int _IO = []() {
        std::ios::sync_with_stdio(0);
        cin.tie(0); // cout.tie(0);
        return 0;
    }();
    cin >> n;
    cin >> s;
    int res[n];
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            count0++;
        } else {
            count1++;
        }
        int maxn = gcd(max(count0, count1), min(count0, count1));
        for (int j = maxn; j > 0; j--) {
            if (check(i + 1, j)) {
                res[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) { cout << res[i] << ' '; }
    return 0;
}