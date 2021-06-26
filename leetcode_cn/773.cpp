class Solution {
  private:
    set<vector<vector<int>>> f(vector<vector<int>> board) {
        int direction[5] = {0, 1, 0, -1, 0};
        set<vector<vector<int>>> st;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int new_i = i + direction[k];
                        int new_j = j + direction[k + 1];
                        if (new_i >= 0 && new_i < 2 && new_j >= 0 && new_j < 3) {
                            swap(board[i][j], board[new_i][new_j]);
                            st.emplace(board);
                            swap(board[i][j], board[new_i][new_j]);
                        }
                    }
                }
            }
        }
        return st;
    }

  public:
    int slidingPuzzle(vector<vector<int>> &board) {
        vector<vector<int>> end = {{1, 2, 3}, {4, 5, 0}};
        queue<vector<vector<int>> &> q;
        unordered_set<vector<vector<int>> &> st;
        q.emplace(board);
        st.emplace(board);
        int res = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto t_vec = q.front();
                q.pop();
                if (t_vec == end) { return res; }
                auto nst = f(t_vec);
                for (auto n_vec : nst) {
                    if (st.count(n_vec) == 0) {
                        q.emplace(n_vec);
                        st.emplace(n_vec);
                    }
                }
            }
            ++res;
        }
        return res;
    }
};
