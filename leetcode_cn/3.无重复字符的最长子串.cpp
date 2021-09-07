/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
int lengthOfLongestSubstring(string s) {
    int count[356];
    memset(count, -1, sizeof(count));
    int res = 0;
    int left = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int x = s[i];
        left = max(left, count[x] + 1);
        res = max(res, i - left + 1);
        count[x] = i;
    }
    // res = max(n - left, res);
    return res;
}
// @lc code=end

int main() {
    //
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}