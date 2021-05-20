#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
class Solution {
  private:
    bool res;
    int director[5] = {0, 1, 0, -1, 0};
    int rows, cols;
    string word;
    void dfs(vector<vector<char>> &board, int row, int col, int idx) {
        if (idx == word.length())
            res = true;
        else if (row < 0 || row >= rows || col < 0 || col >= cols)
            return;
        else if (board[row][col] != word[idx])
            return;
        else {
            board[row][col] = ' '; // 访问当前
            for (int i = 0; i < 4; i++) {
                dfs(board, row + director[i], col + director[i + 1], idx + 1); // 尝试向四周搜索
            }
            board[row][col] = word[idx];
        }
    }

  public:
    bool exist(vector<vector<char>> &board, string word) {
        res = false;
        this->word = word;
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, 0);
                if (res == true) return true;
            }
        }

        return res;
    }
};
int main() {
    //
    return 0;
}