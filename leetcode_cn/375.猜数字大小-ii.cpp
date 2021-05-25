/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int cost(int l, int r) {
        /* 左闭右开 */
        if (l + 1 >= r) return 0;
        int res = INT_MAX;
        for (int i = l; i < r; i++) { res = min(res, i + max(cost(l, i), cost(i + 1, r))); }
        return res;
    }
    int getMoneyAmount(int n) { return cost(1, n + 1); }
};
// @lc code=end

int main() {
    //
    return 0;
}
