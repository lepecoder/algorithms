/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;

// @lc code=start
class Solution {
  public:
    int dir[5] = {0, 1, 0, -1, 0};
    int rows, cols;
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        rows = matrix.size();
        cols = matrix[0].size();
        auto mem = vector<vector<int>>(rows, vector<int>(cols));
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) { ans = max(ans, dfs(matrix, i, j, mem)); }
        }
        return ans;
    }
    int dfs(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &mem) {
        if (mem[row][col] != 0) return mem[row][col];
        mem[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int ni = row + dir[i];
            int nj = col + dir[i + 1];
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && mat[ni][nj] > mat[row][col]) { mem[row][col] = max(mem[row][col], dfs(mat, ni, nj, mem) + 1); }
        }
        return mem[row][col];
    }
};
// @lc code=end

int main() {
    //
    Solution so;
    vector<vector<int>> mat = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    int ans = so.longestIncreasingPath(mat);
    cout << ans;
    return 0;
}