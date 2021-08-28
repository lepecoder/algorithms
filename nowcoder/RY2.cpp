#include <bits/stdc++.h>
using namespace std;

bool check(char c) {
    if (c >= '0' && c <= '9') return true;
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'Z') return true;
    return false;
}
int main() {
    //
    string s;
    // cin >> s;
    getline(cin, s);
    string ss;
    ss.reserve(s.size());
    for (int i = 0; i < s.size(); i++) {
        if (check(s[i])) {
            ss += s[i];
        } else if (s[i] == '-' && i > 0 && i < s.size() - 1 && check(s[i - 1]) && check(s[i + 1])) { // 连字符
            ss += s[i];
        } else { //非法字符，需要越过一片，保留一个
            int idx = i + 1;
            while (idx < s.size() && check(s[idx]) == false) { idx++; }
            ss += ' ';
            i = idx - 1;
        }
    }
    // cout << ss << endl;
    ss += ' ';
    stack<string> stk;
    int pre = 0;
    for (int i = 0; i < ss.size(); i++) {
        if (ss[i] == ' ') {
            stk.emplace(ss.substr(pre, i - pre));
            pre = i + 1;
        }
    }
    string res;
    res.reserve(ss.size());
    while (!stk.empty()) {
        res += stk.top();
        res += ' ';
        stk.pop();
    }
    cout << res << endl;
    return 0;
}