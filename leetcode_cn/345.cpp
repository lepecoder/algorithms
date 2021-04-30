/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    string reverseVowels(string s) {
        int n = s.size();
        int first = 0, last = n - 1;
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (first < last) {
            while (first < last && vowel.count(s[first]) == 0) first++;
            while (first < last && vowel.count(s[last]) == 0) last--;
            if (first >= last) break;
            swap(s[first], s[last]);
            first++;
            last--;
        }
        return s;
    }
};
// @lc code=end

int main() {
    Solution so;
    string s = "Aa";
    string res = so.reverseVowels(s);
    cout << res;
    return 0;
}