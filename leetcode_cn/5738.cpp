#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int sumBase(int n, int k) {
        /* 把n转化成k进制 */
        int res = 0;
        while (n) {
            res += n % k;
            n = n / k;
        }
        return res;
    }
};
int main() {
    //
    return 0;
}