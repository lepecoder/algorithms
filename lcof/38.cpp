#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<string> res;
    string str;
    void backtrack(string &&path, int vis[]) {
        if (path.length() == str.length()) {
            res.emplace_back(path);
        } else {
            char pre = ' ';
            for (int i = 0; i < str.length(); i++) {
                if (str[i] != pre && vis[i] == 0) { // 可以选这个字符
                    pre = str[i];
                    vis[i] = 1;
                    backtrack(path + str[i], vis);
                    vis[i] = 0;
                }
            }
        }
    }

  public:
    vector<string> permutation(string s) {
        str = s;
        sort(str.begin(), str.end());
        int vis[s.length()];
        memset(vis, 0, sizeof(vis));
        backtrack("", vis);
        return res;
    }
};
int main() {
    //
    return 0;
}