#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        for (int x : nums) cout << x << ' ';
        return nums[k - 1];
        //
    }
};
int main() { return 0; }