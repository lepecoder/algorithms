#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool canPermutePalindrome(string s) {
        // 重新排列后能组成回文串，那么字母出现次数一定是偶数，最多有一个奇数
        unordered_map<char, bool> mp;
        for (char c : s) {
            //
            if (mp.count(c)) {
                mp[c] = !mp[c];
            } else {
                mp[c] = false;
            }
        }
        int count = 0;
        for (auto p : mp) {
            if (p.second == false) count++;
        }
        return count <= 1;
    }
};
int main() {
    Solution so;
    so.canPermutePalindrome("abccaode");
    return 0;
}