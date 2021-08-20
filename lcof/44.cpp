#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findNthDigit(int n) {
        int digit = 1, start = 1, count = 9;
        while (count < n) {
            n -= count;
            start *= 10;
            digit++;
            count = 9 * start * digit;
        }
        int num = start + (n - 1) / digit;
        string s = to_string(num);
        int res = s[(n - 1) % digit] - '0';
        return res;
    }
};

int main() {
    //
    Solution so;
    int ans = so.findNthDigit(13);
    cout << ans << endl;
    return 0;
}