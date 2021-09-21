#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    string compressString(string S) {
        string res;
        int t = 1;
        char pre = S[0];
        int n = S.size();
        if (n == 1) return S;
        for (int i = 1; i < n; i++) {
            if (S[i] == pre) {
                t++;
            } else {
                res += pre;
                res += t + '0';
                t = 1;
                pre = S[i];
            }
        }
        res += pre;
        res += t + '0';
        t = 1;
        pre = S[n - 1];
        return res.size() < S.size() ? res : S;
    }
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int main() {
    //
    return 0;
}