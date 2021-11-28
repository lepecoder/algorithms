#include <bits/stdc++.h>
using namespace std;
#define ll long long
string str;
unordered_set<string> wordlist;

vector<string> res;

void dfs(int idx, string path) {
    if (idx == str.size()) {
        path = path.substr(0, path.size() - 1);
        res.emplace_back(path);

    } else {
        string t;
        for (int i = idx; i < str.size(); i++) {
            t += str[i];
            if (wordlist.count(t)) {
                string npath(path);
                npath += t;
                npath += ' ';
                dfs(i + 1, npath);
            }
        }
    }
}

int main() {
    //
    cin >> str;
    string t;
    while (cin >> t) wordlist.emplace(t);
    string path;
    dfs(0, path);
    if (res.empty()) {
        cout << "NULL";
    } else {
        reverse(res.begin(), res.end());
        for (auto &s : res) { cout << s << endl; }
    }

    return 0;
}