/*
 * @lc app=leetcode.cn id=1510 lang=cpp
 *
 * [1510] 石子游戏 IV
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool winnerSquareGame(int n) {
        bool f[n + 1];
        memset(f, false, sizeof(f));
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k * k <= i; k++) {
                if (f[i - k * k] == false) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};
// @lc code=end

int main() {
    //
    Solution so;
    so.winnerSquareGame(6);
    return 0;
}