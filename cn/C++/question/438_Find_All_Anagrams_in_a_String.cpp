// @algorithm @lc id=438 lang=cpp
// @title find-all-anagrams-in-a-string

#include "algm/algm.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @test("cbaebabacd","abc")=[0,6]
// @test("abab","ab")=[0,1,2]
class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.length(), plen = p.length();
        if (slen < plen) return {};
        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        for (int i = 0; i < plen; i++) {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }
        if (sCount == pCount) { ans.emplace_back(0); }

        for (int i = 0; i < slen - plen; i++) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + plen] - 'a'];
            if (sCount == pCount) { ans.emplace_back(i + 1); }
        }
        return ans;
    }
};