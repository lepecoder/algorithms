/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool judgeSquareSum(int c) {
        int upper = ceil(sqrt(c));
        for (long a = 0; a <= upper; a++) {
            long square_b = c - pow(a, 2);
            if (square_b < 0) continue;
            if (long(sqrt(square_b)) * long(sqrt(square_b)) == square_b) return true;
        }
        return false;
    }
};
// @lc code=end

int main() {
    // cout << (1ll << 31);
    cout << sqrt(1234);
    return 0;
}