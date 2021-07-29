#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string replaceSpaces(string S, int length) {
        string res = "";
        res.reserve(S.length());
        for (int i = 0; i < length; i++) {
            if (S[i] == ' ') {
                res += "%20";
            } else {
                res += S[i];
            }
        }
        return res;
    }
};

int main() {
    //
    return 0;
}