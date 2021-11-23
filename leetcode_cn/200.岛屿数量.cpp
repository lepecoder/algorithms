/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @lc code=start
class Solution {
  public:
    int dir[5] = {0, 1, 0, -1, 0};
    int n, m;
    void fun(vector<vector<char>> &grid, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (grid[x][y] == '1') {
            grid[x][y] = '0';
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];
                fun(grid, nx, ny);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    fun(grid, i, j);
                }
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
