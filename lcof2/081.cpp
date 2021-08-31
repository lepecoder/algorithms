#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> candi;
    int n;
    int target;
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(int sum, int idx) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = idx; i < n; i++) {
            int x = candi[i];
            path.push_back(x);
            backtrack(sum + x, i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        res.clear();
        candi = candidates;
        n = candi.size();
        this->target = target;
        // vector<int> path;
        path.clear();
        backtrack(0, 0);
        return res;
    }
};

int main() {
    //
    return 0;
}