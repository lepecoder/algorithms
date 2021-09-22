#include <bits/stdc++.h>
using namespace std;
#define ll long long
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
class Solution {
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 1;
        int n = numbers.size();
        int x = numbers[0];
        for (int i = 1; i < n; i++) {
            if (numbers[i] == x) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                count = 1;
                x = numbers[i];
            }
        }
        return x;
    }
};
int main() {
    //
    return 0;
}