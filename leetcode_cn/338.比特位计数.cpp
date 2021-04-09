/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        int arr[] = {0, 1, 1, 2, 1};
        // 先初始化前几个
        for (int i = 0; i <= min(num, 4); i++) { res[i] = arr[i]; }
        int k = 4, i = 1;
        while (i + k <= num) {
            if (i < k) {
                res[i + k] = res[i] + res[k];
                i++;
            } else { // i==k
                k = k << 1;
                res[k] = 1;
                i = 1;
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    auto res = so.countBits(4);
    for (auto &x : res) { cout << x << ' '; }
    return 0;
}