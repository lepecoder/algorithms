/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int totalHammingDistance(vector<int> &nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < 30; i++) {
            int c = 0;
            for (int &e : nums) { c += (e >> i) & 1; }
            res += c * (n - c);
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}