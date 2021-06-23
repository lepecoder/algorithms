#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        vector<int> res;
        res.reserve(m * n);
        int i = 0, i_l = 0, i_r = n - 1; // 列
        bool bi = true;
        int j = 0, j_t = 0, j_d = m - 1; // 行遍历
        bool bj = true;
        while (i_l <= i_r && j_t <= j_d) {
            if (bi) {
                for (i = i_l; i <= i_r; ++i) {
                    // cout << matrix[j][i] << ' ';
                    res.emplace_back(matrix[j][i]);
                }
                ++j_t;
                i--;
            } else {
                for (i = i_r; i >= i_l; --i) {
                    // cout << matrix[j][i] << ' ';
                    res.emplace_back(matrix[j][i]);
                }
                --j_d;
                i++;
            }
            bi = !bi;
            if (bj) {
                for (j = j_t; j <= j_d; ++j) {
                    // cout << matrix[j][i] << ' ';
                    res.emplace_back(matrix[j][i]);
                }
                --i_r;
                j--;
            } else {
                for (j = j_d; j >= j_t; --j) {
                    // cout << matrix[j][i] << ' ';
                    res.emplace_back(matrix[j][i]);
                }
                ++i_l;
                j++;
            }
            bj = !bj;
        }
        return res;
    }
};
int main() {
    //
    return 0;
}