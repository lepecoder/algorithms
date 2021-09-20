#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    int n;
    cin >> n;
    map<char, char> mp;
    mp.emplace(')', '(');
    mp.emplace(']', '[');
    mp.emplace('}', '{');
    while (n--) {
        string s;
        cin >> s;
        stack<char> stk;
        int i;
        for (i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                stk.emplace(c);
            } else {
                if (stk.empty()) {
                    cout << "no" << endl;
                    break;
                }
                if (stk.top() != mp[c]) {
                    cout << "no" << endl;
                    break;
                }
                stk.pop();
            }
        }
        if (i == s.size()) { cout << "yes" << endl; }
    }
    return 0;
}