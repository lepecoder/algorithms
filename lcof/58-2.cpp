#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string reverseLeftWords(string s, int n) {
        string s1 = s.substr(0, 2);
        string s2 = s.substr(2);
        return s2 + s1;
    }
};
int main() {
    //
    return 0;
}