#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    vector<vector<int>> res;
    int n;
    void generate(vector<int> &nums, int idx) {
        if (idx == n) {
            res.emplace_back(nums);
        } else {
            unordered_set<int> st;
            for (int i = idx; i < n; i++) {
                if (!st.count(nums[i])) {
                    st.emplace(nums[i]);
                    swap(nums[idx], nums[i]);
                    generate(nums, idx + 1);
                    swap(nums[idx], nums[i]);
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        n = nums.size();
        generate(nums, 0);
        return res;
    }
};
int main() {
    //
    return 0;
}