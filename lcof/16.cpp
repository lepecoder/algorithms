#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    double myPow(double x, int n) {
        bool b = true;
        long t = n;
        if (n < 0) {
            t = -t;
            b = false;
        }
        double res = 1;
        double base = x;
        while (t) {
            if ((t & 1)) { res *= base; }
            base *= base; // base每次都倍增，但是只有二进制位为1才乘到结果上
            t >>= 1;
        }
        if (b) { return res; }
        return 1 / res;
    }
};
int main() { int n = return 0; }