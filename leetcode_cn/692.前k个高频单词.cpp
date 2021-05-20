/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
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
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> mp;
        for (string &w : words) { mp[w]++; }
        vector<string> res;
        for (auto &[key, value] : mp) { res.emplace_back(key); }
        sort(res.begin(), res.end(), [&](const string &a, const string &b) -> bool {
            return mp[a] == mp[b] ? a < b : mp[a] > mp[b]; // 利用map对vector排序
        });
        res.erase(res.begin() + k, res.end());
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}