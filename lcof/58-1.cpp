#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string reverseWords(string s) {
        string res;
        int n = s.length();
        int r = n - 1; // r指向单词结尾
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                res += s.substr(i + 1, r - i);
                r = i;
            }
        }
        res += s.substr(0, r + 1);
        return res;
    }
};
int main() {
    //
    return 0;
}