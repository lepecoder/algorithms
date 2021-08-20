#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool verifyPostorder(vector<int> &postorder) {
        if (postorder.empty()) return true;
        int n = postorder.size();
        int key = postorder.back();
        vector<int> left;
        vector<int> right;
        int i = 0;
        for (; i < n - 1; i++) {
            if (postorder[i] < key) {
                left.emplace_back(postorder[i]);
            } else {
                break;
            }
        }
        for (; i < n - 1; i++) {
            if (postorder[i] > key) {
                right.emplace_back(postorder[i]);
            } else {
                break;
            }
        }
        if (i == n - 1) {
            return verifyPostorder(left) && verifyPostorder(right);
        } else {
            return false;
        }
    }
};
int main() {
    //
    return 0;
}