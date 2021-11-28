// @algorithm @lc id=594 lang=cpp
// @title longest-harmonious-subsequence

#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// @test([1,3,2,2,5,2,3,7])=5
// @test([1,2,3,4])=2
// @test([1,1,1,1])=0
class Solution {
  public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> mp;
        int res = 0;
        for (int x : nums) { mp[x]++; }
        for (auto [k, v] : mp) {
            if (mp.count(k + 1)) { res = max(res, v + mp[k + 1]); }
        }
        return res;
    }
};