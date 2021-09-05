/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<int> res;
        if (n == 0) return res;
        int m = matrix[0].size();
        res.reserve(n * m);
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom) {
            for (int j = left; j <= right; j++) { res.emplace_back(matrix[top][j]); }
            top++;
            if (top > bottom) break;
            for (int i = top; i <= bottom; i++) { res.emplace_back(matrix[i][right]); }
            right--;
            if (left > right) break;
            for (int j = right; j >= left; j--) { res.emplace_back(matrix[bottom][j]); }
            bottom--;
            if (top > bottom) break;
            for (int i = bottom; i >= top; i--) { res.emplace_back(matrix[i][left]); }
            left++;
            if (left > right) break;
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    vector<vector<int>> mat{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution so;
    auto ans = so.spiralOrder(mat);
    for (int x : ans) { cout << x << ' '; }
    return 0;
}