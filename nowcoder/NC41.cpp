#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int> &arr) {
        // write code here
        unordered_map<int, int> mp; // 元素-出现位置
        int res = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (mp.count(arr[i])) { // 出现重复元素
                i = mp[arr[i]];
                mp.clear();
            } else {
                mp[arr[i]] = i;
                res = max(res, int(mp.size()));
            }
        }
        return res;
    }
};
int main() {
    //
    return 0;
}