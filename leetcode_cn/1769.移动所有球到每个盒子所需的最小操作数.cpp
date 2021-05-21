/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
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
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int t;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            t = 0;
            for (int j = 0; j < n; j++) {
                if (boxes[j] == '1') { t += (abs(i - j)); }
            }
            res[i] = t;
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}