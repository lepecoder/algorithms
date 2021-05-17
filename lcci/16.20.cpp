#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<string> getValidT9Words(string num, vector<string> &words) {
        int key[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
        int n = words.size();
        bool bs[n];
        memset(bs, 1, sizeof(bs));
        int t;
        for (int i = 0; i < num.size(); i++) {
            t = num[i] - '0';
            for (int j = 0; j < words.size(); j++) {
                int idx = words[j][i] - 'a';
                if (key[idx] != t) { bs[j] = false; }
            }
        }
        vector<string> res;
        for (int i = 0; i < n; i++) {
            if (bs[i]) { res.emplace_back(words[i]); }
        }
        return res;
    }
};
int main() {
    Solution so;
    vector<string> words = {"tree", "used"};
    auto res = so.getValidT9Words("8733", words);
    return 0;
}
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();