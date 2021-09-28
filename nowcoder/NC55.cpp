#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    /**
     *
     * @param strs string字符串vector
     * @return string字符串
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write code here
        int n = strs.size();
        string res = strs[0];
        int idx = res.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < idx; j++) {
                if (res[j] != strs[i][j]) { idx = j; }
            }
        }
        return res.substr(0, idx);
    }
};
int main() {
    //
    return 0;
}
