#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isStraight(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count0 = 0;
        int idx = 0;
        while (idx < n && nums[idx] == 0) {
            idx++;
            count0++;
        }
        if (idx >= n - 1) return true;
        int pre = nums[idx++];
        for (int i = idx; i < n; i++) {
            if (nums[i] == pre) {
                return false;
            } else if (nums[i] == pre + 1) {
                pre++;
            } else {
                count0 -= (nums[i] - pre - 1);
                if (count0 < 0) return false;
                pre = nums[i];
            }
        }
        return true;
    }
};
int main() {
    //
    return 0;
}