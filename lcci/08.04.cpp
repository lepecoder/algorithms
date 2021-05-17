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
    vector<int> nums;
    vector<vector<int>> res;
    void backtrack(vector<int> path, int idx) {
        res.emplace_back(path);
        // path.emplace_back(nums[idx]);
        for (int i = idx; i < nums.size(); i++) {
            if (i == idx || nums[i] != nums[i - 1]) {
                path.emplace_back(nums[i]);
                backtrack(path, i + 1);
                path.pop_back();
            }
        }
    }

  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        res.clear();
        this->nums = nums;
        backtrack({}, 0);
        return res;
    }
};
int main() {
    //
    return 0;
}