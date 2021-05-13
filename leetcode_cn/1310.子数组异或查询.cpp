/*
 * @lc app=leetcode.cn id=1310 lang=cpp
 *
 * [1310] 子数组异或查询
 */
#include <bits/stdc++.h>
using namespace std;

// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
// @lc code=start
class Solution {
  public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        vector<int> res;
        res.reserve(queries.size());
        int prearr[arr.size() + 1];
        int left, right, t;
        prearr[0] = 0;
        for (int i = 1; i <= arr.size(); i++) { prearr[i] = prearr[i - 1] ^ arr[i - 1]; }
        for (auto &v : queries) {
            left = v[0];
            right = v[1];
            if (left == right)
                t = arr[left];
            else {
                t = prearr[right + 1] ^ prearr[left];
            }
            res.emplace_back(t);
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}