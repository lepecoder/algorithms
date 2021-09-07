#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int ones = 0, twos = 0;
        for (int &n : nums) {
            ones = ones ^ n & ~twos;
            twos = twos ^ n & ~ones;
        }
        return ones;
    }
};
int main() {
    //
    return 0;
}