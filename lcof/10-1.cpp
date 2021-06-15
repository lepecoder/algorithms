#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int fib(int n) {
        if (n < 2) return n;
        int a = 0, b = 1;
        int c;
        for (int i = 2; i <= n; i++) {
            if (a + b > 1000000007) {
                c = a + b - 1000000007;
            } else {
                c = a + b;
            }
            a = b;
            b = c;
        }
        return c;
    }
};
int main() {
    //
    return 0;
}