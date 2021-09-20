#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    int n;
    map<char, char> mp;
    mp.emplace(')', '(');
    mp.emplace(']', '[');
    mp.emplace('}', '{');
    cin >> n;
    while (n--) {
        string s;
        int res = 0;
        cin >> s;
        stack<char> stk;
        for (char &c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.emplace(c);
            } else {
                if (stk.top() == mp[c]) {
                    stk.pop();
                } else {
                    res++;
                    stk.pop();
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}