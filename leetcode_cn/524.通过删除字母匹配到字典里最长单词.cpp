#include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>
// #include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool comp(string s1, string s2) {
        if (s1.size() == s2.size()) { return s1 < s2; }
        return s1.size() > s2.size();
    }
    bool check(string s1, string s2) {
        // 检查s1中是否包含s2
        int k = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[k]) k++;
        }
        return k == s2.size();
    }
    string findLongestWord(string s, vector<string> &dictionary) {
        sort(dictionary.begin(), dictionary.end(), comp);
        for (auto &s2 : dictionary) {
            if (check(s, s2)) return s2;
        }
        return "";
    }
};
// @lc code=end

int main() {
    //
    Solution so;
    string s = "wordgoodgoodgoodbestword";
    vector<string> dict = {"word", "good", "best", "good"};
    string ans = so.findLongestWord(s, dict);
    // for (auto &s : dict) { cout << s << ' '; }
    cout << ans;
    return 0;
}