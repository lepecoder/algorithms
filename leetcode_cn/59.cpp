class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int top = 0;
        int left = 0;
        int right = n - 1;
        int down = n - 1;
        int k = 1;
        while (top <= down && left <= right) {
            // top
            for (int j = left; j <= right; j++) { res[top][j] = k++; }
            top++;
            if (top > down) break;
            for (int i = top; i <= down; i++) { res[i][right - 1] = k++; }
            right--;
            if (left > right) break;
            for (int j = right; j >= left; j--) { res[down][j] = k++; }
            down--;
            if (top > down) break;
            for (int i = down; i >= top; i--) { res[i][left] = k++; }
            left++;
        }
        return res;
    }
};
