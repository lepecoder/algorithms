#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
class Solution {
  private:
    vector<string> res;
    void backtrack(string path, int a, int b) {
        /* ab是左右括号可选择的数量
        当a==b==0时，结束，添加的结果集合
        必须保证先左括号后右括号，因此需要保证a<=b */
        if (a == 0 && b == 0) {
            res.emplace_back(path);
        } else if (a == b) {
            // 只能选左括号
            // path = path+"(";
            string s1 = path + "(";
            backtrack(s1, a - 1, b);
        } else {
            string s2 = path + "(";
            backtrack(s2, a - 1, b);
            string s3 = path + ")";
            backtrack(s3, a, b - 1);
        }
    }

  public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        backtrack("", n, n);
        return res;
    }
};
int main() {
    //
    return 0;
}