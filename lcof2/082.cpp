#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> candi;
    vector<vector<int>> res;
    int targ;

    void backtrack(vector<int> &path, int sum, int idx) {
        if (sum == targ) {
            res.emplace_back(path);
        } else if (sum < targ) {
            for (int i = idx; i < candi.size(); i++) {
                if (i > idx && candi[i] == candi[i - 1]) continue;
                path.emplace_back(candi[i]);
                backtrack(path, sum + candi[i], i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        res.clear();
        candi = candidates;
        sort(candi.begin(), candi.end());
        targ = target;
        vector<int> path;
        backtrack(path, 0, 0);
        return res;
    }
};
int main() {
    //
    return 0;
}