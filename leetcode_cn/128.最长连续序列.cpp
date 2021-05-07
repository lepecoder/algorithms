#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> uset;
        for (int &x : nums) uset.emplace(x);
        int res = 0;
        int t;
        for (auto it = uset.begin(); it != uset.end(); it++) {
            t = *it;
            if (uset.count(t - 1)) continue;
            do { t++; } while (uset.count(t));
            res = max(res, t - *it);
        }
        return res;
    }
};

int main() {
    //
    return 0;
}