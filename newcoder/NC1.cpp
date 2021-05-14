#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        string res;
        int carry = 0;
        // 让s比t长
        if (s.length() < t.length()) swap(s, t);
        while (t.length() < s.length()) t = "0" + t;
        t = "0" + t;
        s = "0" + s;
        int n = s.length();
        int temp;
        for (int i = n - 1; i >= 0; i--) {
            temp = carry + int(s[i]) - '0' + int(t[i]) - '0';
            if (temp >= 10) {
                temp -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res = to_string(temp) + res;
        }
        // 删除前导0,最多1个
        if (res[0] == '0') { res = string(res.begin() + 1, res.end()); }
        return res;
    }
};
int main() {
    Solution so;
    string res = so.solve("8", "998");
    cout << res;
    return 0;
}
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();