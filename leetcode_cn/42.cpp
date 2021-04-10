#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int trap(vector<int> &height) {
        // 接雨水
        int n = height.size();
        if (n < 3) { return 0; }
        vector<int> v(n);
        int max_ = height[0];
        for (int i = 0; i < n; i++) {
            v[i] = max(max_, height[i]);
            max_ = v[i];
        }
        max_ = height[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            v[i] = min(v[i], max(max_, height[i]));
            max_ = v[i];
        }
        for (auto &x : v) { cout << x << ' '; }
        return accumulate(v.begin(), v.end(), 0) - accumulate(height.begin(), height.end(), 0);
    }
};
int main() {
    Solution so;
    vector<int> height = {4, 2, 3, 2, 5};
    int ans = so.trap(height);
    cout << endl << ans;
    return 0;
}