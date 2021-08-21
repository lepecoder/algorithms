// 小易爱回文
#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    string s1;
    cin >> s1;
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int n = s1.size();
    for (int i = 0; i < n; i++) {
        int t = n - i;
        string t1 = s1.substr(i);
        string t2 = s2.substr(0, t);
        if (t1 == t2) {
            s1 += s2.substr(t);
            cout << s1;
            break;
        }
    }
    return 0;
}