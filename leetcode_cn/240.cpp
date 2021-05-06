/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size() - 1;
        int n = 0, t;
        while (m >= 0 && n < matrix[0].size()) {
            t = matrix[m][n];
            if (t == target)
                return true;
            else if (t < target) {
                n++;
            } else {
                m--;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution so;
    // vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    vector<vector<int>> matrix = {{5}, {6}};
    bool res = so.searchMatrix(matrix, 6);
    cout << res;
    return 0;
}