#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    vector<vector<int>> res;
    // vector<int> nums;
    void backtrack(vector<int> &nums, int idx) {
        if (idx == nums.size()) {
            res.emplace_back(nums);
        } else {
            for (int i = idx; i < nums.size(); i++) {
                swap(nums[i], nums[idx]);
                backtrack(nums, i + 1);
                swap(nums[i], nums[idx]);
            }
        }
    }

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        // res.clear();
        backtrack(nums, 0);
        return res;
    }
};
int main() {
    //
    return 0;
}