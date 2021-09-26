/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @lc code=start
class Solution {
  public:
    vector<string> res;
    int n;
    void fun(string s, int idx, int k, string path) {
        if (idx == n && k == 4) {
            res.emplace_back(path);
            return;
        }
        if (k >= 4) { return; }
        // 取一个数字
        int t = 0;
        for (int i = idx; i < n; i++) {
            // 跳过连续的0
            t = t * 10 + s[i] - '0';
            // if (t == 0 && i > idx) continue;
            if (t > 255) break;
            string ts = to_string(t);
            string tpath(path);
            tpath += ts;
            if (k < 3) tpath += '.';
            fun(s, i + 1, k + 1, tpath);
            if (t == 0) break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        string path;
        fun(s, 0, 0, path);
        return res;
    }
};
// @lc code=end

int main() {
    //
    Solution so;
    auto ans = so.restoreIpAddresses("25525511135");
    for (string s : ans) { cout << s << endl; }
    return 0;
}