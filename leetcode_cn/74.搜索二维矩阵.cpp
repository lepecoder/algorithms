/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = m * n - 1;
    int mid, t;
    while (i <= j) {
      mid = (i + j) / 2;
      t = matrix[mid / n][mid % n];
      if (t == target) {
        return true;
      } else if (t < target) { // 右边找
        i = mid + 1;
      } else {
        j = mid - 1;
      }
    }
    return false;
  }
};

// @lc code=end

int main() {
  //
  return 0;
}