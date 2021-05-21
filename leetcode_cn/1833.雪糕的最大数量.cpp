/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 *
 * [1833] 雪糕的最大数量
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
    int maxIceCream(vector<int> &costs, int coins) {
        /* 01背包问题，每支雪糕可以选择买或不买, 要求数量最大*/
        int n = costs.size();
        /* 贪心就完事了，因为每支雪糕只有价格属性 */
        sort(costs.begin(), costs.end());
        int sum = 0;
        int res = 0;
        for (int &e : costs) {
            if (sum + e <= coins) {
                res++;
                sum += e;
            } else {
                break;
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