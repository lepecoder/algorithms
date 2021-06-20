#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int numWays(int n) {
        int a = 1, b = 1;
        for (int i = 2; i <= n; i++) {
            b = a + b;
            a = b - a;
        }
        return a;
    }
};
int main() {
    //
    return 0;
}