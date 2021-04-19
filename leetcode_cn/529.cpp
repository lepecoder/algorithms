/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
    typedef vector<vector<char>> vvc;

  public:
    int m, n;
    inline bool check(int a, int b, int delta_a, int delta_b) {
        /* 检查是否越界 */
        if (a + delta_a >= 0 && a + delta_a < m) {
            if (b + delta_b >= 0 && b + delta_b < n) { return true; }
        }
        return false;
    }
    vvc updateBoard(vvc &board, const vector<int> &click) {
        /* 扫雷
        直接在board上改
         */
        m = board.size();    // 行
        n = board[0].size(); // 列
        int a = click[0], b = click[1];
        if (!check(a, b, 0, 0)) { // click的位置不合法，直接返回
            return board;
        }

        for (auto &v : board) {
            for (auto &w : v) { cout << w << ' '; }
            cout << endl;
        }
        cout << a << ' ' << b << "\n--------------\n";
        if (board[a][b] == 'M') { // 命中雷
            board[a][b] = 'X';
            return board;
        }
        // 没有命中雷
        int direct[] = {1, 0, -1, 0, 1, 1, -1, -1, 1}; // 四个方向
        // 可能周围有雷
        int count = 0; // 记录雷的数量
        for (int i = 0; i < 8; i++) {
            if (!check(a, b, direct[i], direct[i + 1])) continue;
            if (board[a + direct[i]][b + direct[i + 1]] == 'M') { ++count; }
        }
        if (count) {
            board[a][b] = count + '0';
            return board;
        }
        // 周围没有雷，那么这个格子应该是空白，并且需要在上下左右各敲了一次
        // 为了避免无限递归，需要判断这个格子是覆盖的E状态
        board[a][b] = 'B';
        for (int i = 0; i < 8; i++) {
            if (!check(a, b, direct[i], direct[i + 1])) continue;
            if (board[a + direct[i]][b + direct[i + 1]] == 'E') {
                vector<int> cli = {a + direct[i], b + direct[i + 1]};
                updateBoard(board, cli);
            }
        }
        return board;
    }
};
// @lc code=end

int main() {
    //
    Solution so;
    vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'M', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}};

    vector<int> click = {3, 0};
    so.updateBoard(board, click);
    for (auto &v : board) {
        for (auto &w : v) { cout << w << ' '; }
        cout << endl;
    }

    return 0;
}