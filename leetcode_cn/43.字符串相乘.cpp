/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    string addStrings(string num1, string num2) {
        // 两个字符串相加
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        ans.reserve(max(i, j) + 3);
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        // 计算完以后的答案需要翻转过来
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string mul(string num1, char num2) {
        // 字符串和一个字符相乘
        int i = num1.length() - 1;
        int x = num2 - '0';
        if (x == 0) return "0";
        int add = 0;
        string res = "";
        res.reserve(i + 3);
        while (i >= 0 || add != 0) {
            int y = i >= 0 ? num1[i] - '0' : 0;
            int t = x * y + add;
            res.push_back('0' + t % 10);
            add = t / 10;
            i--;
        }
        reverse(res.begin(), res.end());
        // cout << num1 << '*' << num2 << '=' << res << endl;
        return res;
    }

    string multiply(string num1, string num2) {
        string res = "", add = "0";
        // int i = num1.length()-1, j = num2.length()-1;
        int i, j;
        for (i = 0; i < num2.length(); i++) {
            string t = mul(num1, num2[i]);
            if (res[0] != '0') res.push_back('0');
            res = addStrings(res, t);
            // cout << res << endl;
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    string res = so.multiply("0", "456");
    cout << res << endl;
    return 0;
}
