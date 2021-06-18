#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                return {nums[i], nums[j]};
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {};
    }
};
int main() {
    //
    return 0;
}