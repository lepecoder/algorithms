/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int xorOperation(int n, int start) {
        int res = 0;
        for (int i = 0; i < n; i++) { res = res ^ (start + 2 * i); }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}