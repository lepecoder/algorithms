#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
  public:
    vector<bool> vis;
    vector<vector<int>> res;
    void backtrack(vector<int> &nums, int idx, vector<int> &path) {
        cout << idx << ' ';
        if (idx == nums.size()) {
            res.emplace_back(path);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) continue;
                path.emplace_back(nums[i]);
                vis[i] = true;
                backtrack(nums, idx + 1, path);
                vis[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vis.resize(nums.size());
        backtrack(nums, 0, path);
        return res;
    }
};
int main() {
    Solution so;
    vector<int> nums = {1, 1, 2};
    auto ans = so.permuteUnique(nums);
    //
    return 0;
}