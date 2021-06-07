#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> exchange(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            // 找到左边第一个偶数
            while ((nums[l] & 1) == 1) l++;
            // 找到右边第一个奇数
            while ((nums[r] & 1) == 1) r--;
            swap(nums[l], nums[r]);
        }
        return nums;
    }
};

int main() {
    //
    return 0;
}