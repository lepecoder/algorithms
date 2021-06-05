/*
 * @lc app=leetcode.cn id=1399 lang=cpp
 *
 * [1399] 统计最大组的数目
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int countLargestGroup(int n) {
        vector<int> S(n + 1, 0);
        vector<int> C(37, 0);
        for (int i = 1; i <= n; i++) {
            S[i] = S[i / 10] + i % 10;
            C[S[i]]++;
        }
        int x = *max_element(C.begin(), C.end());
        return count(C.begin(), C.end(), x);
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
