#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    vector<string> res;
    string s;
    void backtrack(string &&path, bool *bs) {
        /* path记录已经产生的串，bs记录s里某个字符串是否被选择， */
        if (path.size() == s.size()) {
            res.emplace_back(path);
        } else {
            for (int i = 0; i < s.size(); i++) {
                if (bs[i] == false) {
                    bs[i] = true;
                    backtrack(path + s[i], bs);
                    bs[i] = false;
                }
            }
        }
    }

  public:
    vector<string> permutation(string S) {
        s = S;
        res.clear();
        bool bs[s.size()];
        memset(bs, 0, sizeof(bs));
        backtrack("", bs);
        return res;
    }
};
int main() {
    //
    return 0;
}
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();