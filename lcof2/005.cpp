#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxProduct(vector<string> &words) {
        int n = words.size();
        vector<bitset<26>> bitwords(n, bitset<26>());
        for (int i = 0; i < n; i++) {
            for (char &c : words[i]) { bitwords[i][c - 'a'] = true; }
        }
        decltype(words[0].size()) res = 0;
        // size_t y = 12;
        // cout << typeid(y).name() << endl;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((bitwords[i] & bitwords[j]) == 0) res = max(res, words[i].size() * words[j].size());
            }
        }
        return res;
    }
};
int main() {
    //
    Solution so;
    vector<string> words = {"awd", "lkj"};
    int ans = so.maxProduct(words);
    cout << ans;
    return 0;
}