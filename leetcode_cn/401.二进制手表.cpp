/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) { res.emplace_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m)); }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}