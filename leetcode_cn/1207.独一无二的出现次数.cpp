/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> mp1; // 记录数字出现次数
        for (int &e : arr) { mp1[e]++; }
        int mp[arr.size()];
        memset(mp, 0, sizeof(mp));
        for (pair<const int, int> &p : mp1) {
            mp[p.second]++;
            if (mp[p.second] > 1) { return false; }
        }
        return true;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
