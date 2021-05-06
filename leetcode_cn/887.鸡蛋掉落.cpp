/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int superEggDrop(int k, int n) {
        n++;
        if (k == 1) return n - 1;
        if (n == 2) return 1;
        // if (k == 1 || n <= 1) return n;
        int res = 0;
        while (true) {
            if (k == 1) return res + n - 1;
            if (n == 2) return res + 1;
            if (n == 1) return res;
            k--;
            n = n / 2;
            res++;
        }
        // return superEggDrop(k - 1, ceil(n / 2.0));
    }
};
// @lc code=end

int main() {
    Solution so;
    int res = so.superEggDrop(2, 6);
    cout << res;
    return 0;
}
