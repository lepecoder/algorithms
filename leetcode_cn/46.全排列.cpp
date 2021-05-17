#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    vector<vector<int>> res;
    void backtrack(vector<int> &path, int idx) {
        if (idx == path.size()) {
            res.emplace_back(path);
        } else {
            for (int i = idx; i < path.size(); i++) {
                swap(path[i], path[idx]);
                backtrack(path, idx + 1);
                swap(path[i], path[idx]);
            }
        }
    }

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        res.clear();
        backtrack(nums, 0);
        return res;
    }
};
int main() {
    //
    return 0;
}
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();