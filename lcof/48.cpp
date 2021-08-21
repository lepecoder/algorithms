#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; // 字符和字符出现的位置
        int res = 0;
        int n = s.size();
        int i = 0, j, k;
        char c;
        for (j = 0; j < n; j++) {
            c = s[j];
            if (mp.count(c) == 0 || mp[c] == -1) { // 和之前的字符不重复
                mp[c] = j;
                res = max(res, j - i + 1);
            } else { // 和之前的有重复，找到重复位置，计算res
                k = mp[c];
                for (; i <= k; i++) { // 删除mp里的映射
                    mp[s[i]] = -1;
                }
                mp[c] = j;
            }
        }
        return res;
    }
};
int main() {
    Solution so;
    int ans = so.lengthOfLongestSubstring("abcabcabc");
    cout << ans;

    return 0;
}