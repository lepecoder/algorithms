#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool find132pattern(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) return false;
        // 记录当前左侧的最小值
        int left_min = nums[0];
        // 记录右侧元素，用于查找是否有132模式中的2
        multiset<int> right_all;
        for (int i = 2; i < n; i++) { right_all.insert(nums[i]); }
        // 遍历132模式中的3
        for (int i = 1; i < n - 1; i++) {
            if (left_min < nums[i]) { // i可以作为3
                                      // set里的数字会按照key排序，upper_bound
                multiset<int>::iterator it = right_all.upper_bound(left_min);
                if (it != right_all.end() && *it < nums[i]) return true;
            } else {
                left_min = nums[i];
            }
            right_all.erase(right_all.find(nums[i + 1]));
        }

        return false;
    }
};
int main() {
    Solution so;
    vector<int> v{3, 5, 0, 3, 4};
    cout << so.find132pattern(v);
    return 0;
}