/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    static bool comp(int &n, int &m) {
        string s1 = to_string(n);
        string s2 = to_string(m);
        string a = s1 + s2;
        string b = s2 + s1;
        return a > b;
    }
    string largestNumber(vector<int> &nums) {
        //
        sort(nums.begin(), nums.end(), comp);
        string res = "";
        for (auto &x : nums) {
            res += to_string(x);
            // cout << x << ' ';
        }
        if (res[0] == '0') return "0";
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> v{0, 0};
    string ans = so.largestNumber(v);
    cout << ans;
    return 0;
}