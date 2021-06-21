#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        int i = n - 1;
        int j = 0;
        while (i >= 0 && j < m) {
            int t = matrix[i][j];
            if (t == target)
                return true;
            else if (t > target) {
                --i;
            } else {
                ++j;
            }
        }
        return false;
    }
};
int main() {
    //
    return 0;
}