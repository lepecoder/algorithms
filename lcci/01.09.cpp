#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        string s = s1 + s1;
        auto ans = s.find(s2);
        return ans == string::npos ? false : true;
    }
};
int main() {
    //
    return 0;
}