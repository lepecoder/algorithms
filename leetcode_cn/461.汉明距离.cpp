/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z) {
            res++;
            z = z & (z - 1);
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}