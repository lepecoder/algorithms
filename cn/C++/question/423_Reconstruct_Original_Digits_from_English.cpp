// @algorithm @lc id=423 lang=cpp
// @title reconstruct-original-digits-from-english

#include "algm/algm.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @test("owoztneoer")="012"
// @test("fviefuro")="45"
class Solution {
  public:
    string originalDigits(string s) {
        unordered_map<char, int> c;
        for (char ch : s) { ++c[ch]; }

        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[6] = c['x'];
        cnt[8] = c['g'];

        cnt[3] = c['h'] - cnt[8];
        cnt[5] = c['f'] - cnt[4];
        cnt[7] = c['s'] - cnt[6];

        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) { ans += char(i + '0'); }
        }
        return ans;
    }
};
// int main(int argc, char const *argv[]) {
//     /* code */
//     return 0;
// }
