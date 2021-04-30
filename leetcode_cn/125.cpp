/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isPalindrome(string s) {
        int n = s.size();
        int first = 0, last = n - 1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s;
        while (first < last) {
            while (first < last && !isalnum(s[first])) first++;
            while (first < last && !isalnum(s[last])) last--;
            if (s[first] != s[last]) return false;
            first++;
            last--;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution so;
    string s = "A man, a plan, a canal: Panama";
    bool ans = so.isPalindrome(s);
    cout << ans;
    return 0;
}