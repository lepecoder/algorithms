#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int game(vector<int> &guess, vector<int> &answer) {
        int n = guess.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (guess[i] == answer[i]) ++res;
        }
        return res;
    }
};
int main() {
    //
    return 0;
}