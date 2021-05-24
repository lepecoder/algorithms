/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int> dict;
        for (char &c : s) dict[c]++;
        vector<string> sub(s.size() + 1);
        for (auto &[key, value] : dict) { sub[value].append(value, key); }
        for (int i = s.size(); i > 0; i--) {
            if (sub[i].size()) res.append(sub[i]);
        }
        return res;
    }
};
// @lc code=end

int main() {
    //
    return 0;
}
