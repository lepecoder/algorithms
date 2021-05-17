#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool oneEditAway(string first, string second) {
        if (first == second) return true;
        int n = first.length();
        int m = first.length();
        if (abs(n - m) > 1) return false;
        int dp[n][m];
    }
};
int main() {
    //
    return 0;
}
// IO
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();