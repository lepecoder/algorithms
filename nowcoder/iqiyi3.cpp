#include <bits/stdc++.h>
using namespace std;
// vector<unordered_set<int>> res1;
int n;
vector<vector<string>> res;
bool check(int row, int col, vector<string> &chess) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        if (chess[i][col] == 'Q') { return false; }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (chess[i][j] == 'Q') { return false; }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
        if (chess[i][j] == 'Q') return false;
    }
    return true;
}
void backtrack(int row, vector<string> &chess) {
    // 第row行
    if (row == n) {
        res.emplace_back(chess);
        return;
    }
    for (int c = 0; c < n; c++) {
        if (check(row, c, chess)) {
            chess[row][c] = 'Q';
            backtrack(row + 1, chess);
            chess[row][c] = '.';
        }
    }
}

int main() {
    //
    // cin >> n;
    string line;
    // cin >> line;
    getline(cin, line);

    line = line.substr(2);
    istringstream stream(line);
    stream >> n;
    vector<string> chess(n, string(n, '.'));
    backtrack(0, chess);
    // for (vector<string> &r : res) {
    for (int i = 0; i < res.size(); i++) {
        if (i == 0) cout << "[";
        vector<string> r = res[i];
        for (int j = 0; j < r.size(); j++) {
            if (j == 0) cout << "[";
            cout << r[j];
            if (j != r.size() - 1) {
                cout << ", ";
            } else {
                cout << "]";
            }
        }
        if (i != res.size() - 1) {
            cout << ", ";
        } else {
            cout << "]";
        }
    }
    return 0;
}