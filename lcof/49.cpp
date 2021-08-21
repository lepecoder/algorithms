#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int nthUglyNumber(int n) {
        if (n <= 6) return n;
        priority_queue<int, vector<int>, greater<int>> qu;
        int x = 1;
        qu.emplace(x);
        for (int i = 1; i < n; i++) {
            int t = qu.top();
            while (!qu.empty() && qu.top() == t) { qu.pop(); }
            if (t < INT_MAX / 2) qu.emplace(t * 2);
            if (t < INT_MAX / 3) qu.emplace(t * 3);
            if (t < INT_MAX / 5) qu.emplace(t * 5);
        }
        return qu.top();
    }
};
int main() {
    //
    Solution so;
    int ans = so.nthUglyNumber(10);
    // vector<int> v{3, 2, 1, 6, 4};
    // sort(v.begin(), v.end(), greater<int>());
    // for (int &x : v) { cout << x << ' '; }
    return 0;
}