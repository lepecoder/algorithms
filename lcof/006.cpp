#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        unordered_map<int, int> mp;
        // unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            int x = numbers[i];
            int y = target - x;
            if (mp.count(y)) { return {mp[y], i}; }
            mp.emplace(x, i);
        }
        return {};
    }
};
int main() {
    //
    return 0;
}