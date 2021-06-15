#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for (int l = 1; l <= target / 2; l++) {
            int r = (-1 + sqrt(1 + 8 * target + 4 * l * l - 4 * l)) / 2;
            if (r * r + r == 2 * target + l * l - l) {
                vector<int> t;
                t.reserve(r - l + 1);
                for (int i = l; i <= r; i++) t.emplace_back(i);
                res.emplace_back(t);
            }
        }
        return res;
    }
};
int main() {
    //
    return 0;
}