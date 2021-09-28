#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int> &arr) {
        // 应该是用滑动窗口
        int n = arr.size();
        int res = 0;
        unordered_map<int, int> mp; // 记录元素的位置k
        int pre = -1;
        for (int i = 0; i < n; i++) {
            if (mp.count(arr[i]) == 0) { // 没有重复
                mp[arr[i]] = i;
                res = max(res, i - pre);
            } else { // 有重复
                pre = max(pre, mp[arr[i]]);
                mp[arr[i]] = i;
            }
        }
        return res;
    }
};
int main() {
    //
    Solution so;
    vector<int> arr = {1, 1, 1};
    int ans = so.maxLength(arr);
    cout << ans;
    return 0;
}