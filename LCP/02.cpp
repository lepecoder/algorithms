#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> fraction(vector<int> &cont) {
        int n = cont.size();
        int a = 1, b = 0; // 初始化分子分母
        for (int i = n - 1; i >= 0; --i) {
            // 先把原来的翻转
            swap(a, b);
            // 然后加上cont[i]
            a += b * cont[i];
        }
        return {a, b};
    }
};

int main() {
    //
    return 0;
}