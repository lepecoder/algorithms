#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    int comp(int n, int m) {
        if (m < n - m) m = n - m;
        int ans = 1;
        for (int i = m + 1; i <= n; i++) ans *= i;
        for (int i = 1; i <= n - m; i++) ans /= i;
        return ans;
    }

  public:
    int paintingPlan(int n, int k) {
        int t, res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                t = (i + j) * n - i * j;
                if (t > k) break;
                if (t == k) res = res + comp(n, i) + comp(n, j);
            }
        }
        return res;
    }
};
int main() { return 0; }
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();