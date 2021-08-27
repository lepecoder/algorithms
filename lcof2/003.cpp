#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int bitcount(int x) {
        int res = 0;
        while (x) {
            if (x & 1) res++;
            x >>= 1;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        // res.reserve(n);
        for (int i = 0; i <= n; i++) { res[i] = bitcount(i); }
        return res;
    }
};
int main() {
    //
    return 0;
}