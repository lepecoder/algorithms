/*
 * @lc app=leetcode.cn id=980 lang=cpp
 *
 * [980] 不同路径 III
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int ans;
    vector<vector<int>> grid;
    int ti, tj;
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {1, 0, -1, 0};
    int n, m;

    int uniquePathsIII(vector<vector<int>> &grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        int todo = 0;
        int si = 0, sj = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1) todo++;
                if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                } else if (grid[i][j] == 2) {
                    ti = i;
                    tj = j;
                }
            }
        }
        ans = 0;
        backtrack(si, sj, todo);
    }
    void backtrack(int i, int j, int todo) {
        todo--;
        if (todo < 0) return;
        if (i == ti && j == tj) {
            if (todo == 0) ans++;
            return;
        }
        grid[i][j] = 3;
        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if (grid[ni][nj] % 2 == 0) { backtrack(ni, nj, todo); }
            }
        }
        grid[i][j] = 0;
    }
};
// @lc code=end

int main() {

    //
    return 0;
}