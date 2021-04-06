#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int ans;
    bool *bool_groups; // 指向数组的指针
    void Nsum(int n, int target1, int target2, vector<int> &groups) {
        // groups中n数之和构成(target1+k*target2),
        // n个数必须是bool_groups中等于false中的数
        if (n == 1) {
            for (int i = 0; i < groups.size(); i++) {
                if (bool_groups[i] == false && (groups[i] - target1) % target2 == 0) {
                    ans++;
                    bool_groups[i] = true;
                }
            }
        } else {
            for (auto &x : groups) {}
        }
    }
    void backtrack(vector<int> &path, vector<int>) int maxHappyGroups(int batchSize, vector<int> &groups) {
        /*
        这是一道回溯题，本质是用n个数字组成最多的k*batchSize
        可以用广度优先搜索，因为使用最少的数字可以构成最多的k*batchsize

         */
        int n = groups.size();
        bool_groups = new bool[n];
        // bool_groups记录groups中的元素有没有被用过
        memset(bool_groups, false, sizeof(bool) * n);
        for (auto &x : groups) {
            // 对Batchsize取余
            x = x % batchSize;
        }
        ans = 0;
    }
};
int main() {
    //
    Solution so;
    vector<int> v = {1, 2, 3, 4, 5, 6};
    int ans = so.maxHappyGroups(3, v);
    return 0;
}