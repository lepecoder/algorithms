#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        int n = nums.size();
        if (n == 0) return res;
        deque<int> de;
        for (int i = 0; i < k; i++) {
            int t = nums[i];
            while (!de.empty() && de.back() < t) de.pop_back();
            de.emplace_back(t);
        }
        res.emplace_back(de.front());
        for (int i = k; i < n; i++) {
            int pop = nums[i - k];
            if (pop == de.front()) de.pop_front();

            int t = nums[i];
            while (!de.empty() && de.back() < t) de.pop_back();
            de.emplace_back(t);
            int ans = de.front();
            res.emplace_back(ans);
        }
        return res;
    }
};
int main() {
    //
    return 0;
}