#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int divide(int a, int b) {
        bool posi = true;
        if (a == 0) //分子为0的情况
            return 0;

        if (a == INT_MIN && b == -1) return INT_MAX;
        if (a == INT_MIN && b == 1) return INT_MIN;
        if (a < 0) {
            a = -a;
            posi = !posi;
        }
        if (b < 0) {
            b = -b;
            posi = !posi;
        }
        int res = 0;
        int t = 0;
        int bb;
        while (a >= b) {
            bb = b;
            t = 1;
            while (a > (bb << 1)) {
                //
                bb <<= 1;
                t <<= 1;
            }
            res += t;
            a -= bb;
        }
        return posi ? res : -res;
    }
};
int main() {
    //
    return 0;
}