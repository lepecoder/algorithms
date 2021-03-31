/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    bool str_in[32] = {0};
    int k = 31;
    while (k >= 0) {
      if (n & 1) {
        str_in[k] = 1;
      }
      --k;
      n = n >> 1;
    }
    uint32_t ans = 0;
    for (int i = 31; i >= 0; i--) {
      ans = 2 * ans + int(str_in[i]);
    }
    return ans;
  }
};
// @lc code=end

int main() {
  Solution so;
  auto ans = so.reverseBits(4294967293);
  cout << endl << ans;
  return 0;
}