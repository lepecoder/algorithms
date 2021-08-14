#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n == 0) return 0;
        char c1 = ' ', c2 = ' ';
        int res = 0;
        int left = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c1 == ' ' || c1 == c) {}
        }
        return res;
    }
};
int main() {
    //
    char c = ' ';
    cout << (c == '\0');
    return 0;
}