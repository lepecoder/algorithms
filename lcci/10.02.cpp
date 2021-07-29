#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<string, vector<string>> mp;
        for (auto str : strs) {
            string s(str);
            sort(s.begin(), s.end());
            if (mp.count(s)) { // 已经有了
                mp[s].push_back(str);
            } else {
                mp[s] = vector{str};
            }
        }
        vector<vector<string>> res;
        for (auto p : mp) { res.push_back(p.second); }
        return res;
    }
};

int main() {
    //
    return 0;
}