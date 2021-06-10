/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
  public:
    int minSteps(int n) {
        // 素数分解，把n分解成几个素数的乘积
        int res = 0;
        int d = 2;
        while (n > 1) {
            while (n % d == 0) {
                res += d;
                n /= d;
            }
            d++;
        }
        return res;
    }
};
// @lc code=end
