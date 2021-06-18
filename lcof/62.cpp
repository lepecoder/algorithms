#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lastRemaining(int n, int m) {
        /*
        长度为n的序列，第一次肯定会删除第m%n个元素，然后剩余n-1长度的序列。
        假设子问题f(n-1,m)最后剩下第x个元素，那么对于f(n,m)来说，
         */
        int res = 0;
        for (int i = 2; i <= n; i++) { res = (res + m) % i; }
        return res;
    }
};

int main() {
    //
    return 0;
}