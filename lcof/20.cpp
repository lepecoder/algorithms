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
    string s;
    int filter_blank(int idx) {
        if (idx == s.length()) return idx;
        while (idx < s.length() && s[idx] == ' ') idx++;
        return idx;
    }
    int filter_num(int idx) {
        /* 过滤整数 */
        if (s[idx] == '+' || s[idx] == '-') {
            idx++;
            if (idx >= s.length() || s[idx] < '0' || s[idx] > '9') return 0;
        }

        while (idx < s.length() && s[idx] >= '0' && s[idx] <= '9') idx++;
        return idx;
    }
    int filter_float(int idx) {
        /* 过滤小数 */
        return idx;
    }

  public:
    bool isNumber(string s) {
        int idx = 0;
        this->s = s;
        // 1. 若干空格
        idx = filter_blank(idx);
        // 2. 一个小数或整数
        int idx1 = filter_num(idx);
        if (idx1 < s.length() && s[idx1] == '.') {
            // 小数点后不跟正负号
            if (s[idx1 + 1] == '+' || s[idx1 + 1] == '-') return false;
            int idx2 = filter_num(idx1 + 1);
            if (idx1 == idx && idx2 == idx1 + 1) return false;
            idx = idx2;
        } else {
            if (idx1 == idx) return false;
            idx = idx1;
        }
        if (idx == s.length()) return true;
        // 3. (可选的)一个'e'或'E'，+ 整数
        if (s[idx] == 'e' || s[idx] == 'E') {
            int idx2 = filter_num(idx + 1);
            if (idx2 == idx + 1) return false;
            idx = idx2;
        }
        if (idx == s.length()) return true;
        // 若干空格
        idx = filter_blank(idx);
        return idx == s.length();
    }
};
int main() {
    //
    Solution so;
    cout << so.isNumber("+.8");
    return 0;
}