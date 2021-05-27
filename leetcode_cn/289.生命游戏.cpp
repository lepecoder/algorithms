/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> bod;
    int n, m;
    inline int countOne(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m) return 0;
        return bod[x][y];
    }
    int countLife(int x, int y) {
        /* 统计(x,y)周围8个格子中活细胞个数 */
        int res = 0;
        int dir[9] = {1, 0, -1, 0, 1, 1, -1, -1, 1};
        for (int i = 0; i < 8; i++) { res += countOne(x + dir[i], y + dir[i + 1]); }
        return res;
    }
    void gameOfLife(vector<vector<int>> &board) {
        bod = board;
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int t = countLife(i, j);
                if (board[i][j] == 1) {
                    if (t < 2 || t > 3) board[i][j] = 0;
                    // if(t<2) board[i][j]=0;
                    // if(t==2 || t==3) board[i][j]=1;
                    // if(t>3) board[i][j]=0;
                } else {
                    if (t == 3) board[i][j] = 1;
                }
            }
        }
        // return board;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
