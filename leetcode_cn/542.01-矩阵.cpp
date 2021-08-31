/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int dir[5] = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        queue<vector<int>> q; // i,j,k  (i,j)离0的距离是k
        // 添加1的位置到任务队列
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.emplace(vector<int>{i, j, 0});
                    res[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                vector<int> p = q.front();
                q.pop();
                // 从p点向四个方向延伸
                for (int d = 0; d < 4; d++) {
                    int i = p[0] + dir[d];
                    int j = p[1] + dir[d + 1];
                    int k = p[2] + 1;
                    if (i >= 0 && i < m && j >= 0 && j < n && res[i][j] > k) { // 离0的最近距离被更新
                        res[i][j] = k;
                        q.emplace(vector<int>{i, j, k});
                    }
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
