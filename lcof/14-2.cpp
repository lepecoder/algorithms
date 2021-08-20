#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        long long int res = 1ll;
        int p = 1e9 + 7;
        // n 是n对3的余数
        // res 是n对3的整数倍
        while (n > 4) {
            res = res * 3 % p;
            n -= 3;
        }
        // 余数n可以是 3 4 2
        cout << res << ' ' << n << endl;
        return res * n % p;
    }
};
int main() {
    //
    cout << 123;
    Solution so;
    so.cuttingRope(15);
    return 0;
}