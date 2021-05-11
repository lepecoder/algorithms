/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 *
 * [1734] 解码异或后的排列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
class Solution {
  public:
    vector<int> decode(vector<int> &encoded) {
        int n = encoded.size();
        int first = 0;
        for (int i = 1; i <= n + 1; i++) first = first ^ i;
        for (int i = 1; i < n; i += 2) { first = first ^ encoded[i]; }
        vector<int> res{first};
        res.reserve(n + 1);
        int pre = first;
        for (int i = 0; i < n; i++) {
            pre = pre ^ encoded[i];
            res.emplace_back(pre);
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}