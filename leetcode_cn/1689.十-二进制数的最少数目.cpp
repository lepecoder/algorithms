/*
 * @lc app=leetcode.cn id=1689 lang=cpp
 *
 * [1689] 十-二进制数的最少数目
 */
#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
// @lc code=start
class Solution {
  public:
    int minPartitions(string n) {
        int res = 0;
        for (int i = 0; i < n.size(); i++) { res = max(res, n[i] - '0'); }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}