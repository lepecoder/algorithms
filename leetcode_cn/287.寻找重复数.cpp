#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size();
        int l = 1, r = n; // 左闭右开
        while (l < r) {
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (int &x : nums) { cnt += x <= m; }
            if (cnt <= m) { // 重复数一定大于cnt
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
int main() {
    //
    return 0;
}