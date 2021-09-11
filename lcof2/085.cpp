#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    vector<string> res;
    void fun(int l, int r, string &path) {
        if (l == 0 && r == 0) {
            res.emplace_back(path);
        } else {
            if (l > 0) {
                path.push_back('(');
                fun(l - 1, r, path);
                path.pop_back();
            }
            if (r > l) {
                path.push_back(')');
                fun(l, r - 1, path);
                path.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string path = "";
        fun()
    }
};
int main() {
    //

    return 0;
}