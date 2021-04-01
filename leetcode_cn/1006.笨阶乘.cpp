/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */
#include <iostream>
// #include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
    int clumsy(int N) {
        int ans[] = {1, 2, 6, 7};
        int remainder[] = {-2, 0, 1, 1};
        if (N <= 4) return ans[N - 1];
        int idx = (N - 3) % 4;
        return N + 1 + remainder[idx];
    }
};
// @lc code=end

int main() {
    //
    Solution so;
    for (int i = 1; i <= 10; i++) { cout << so.clumsy(i) << ' '; }
    return 0;
}

/*
1
2
6
7
7
8
6
9
11
12 */