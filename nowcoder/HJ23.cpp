#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int _IO = []() {
        std::ios::sync_with_stdio(0);
        cin.tie(0); // cout.tie(0);
        return 0;
    }();
    string s;
    int count[26];
    int mincount;
    while (cin >> s) {
        memset(count, 0, sizeof(count));
        for (int i = 0; i < s.size(); i++) { count[s[i] - 'a']++; }
        mincount = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) continue;
            mincount = min(mincount, count[i]);
        }
        for (char &c : s) {
            if (count[c - 'a'] != mincount) { cout << c; }
        }
        cout << endl;
    }
    return 0;
}