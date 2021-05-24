#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int two = 0, one = 0;
        for (int &e : nums) {
            one = one ^ e & ~two;
            two = two ^ e & ~one;
        }
        return one;
    }
};
int main() {
    //
    return 0;
}