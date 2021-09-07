#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/**
 * Note: 类名、方法名、参数名已经指定，请勿修改
 *
 *
 *
 * @param s char字符型一维数组
 * @param sLen int s数组长度
 * @return bool布尔型
 */

class Solution {
  public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     *
     *
     * @param s char字符型vector
     * @return bool布尔型
     */
    bool res = false;
    bool ispar(vector<char> &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void dfs(vector<char> &s, int l, int r, int count) {
        if (count > 3) return;
        if (count == 3 && r != s.size()) return;
        if (r == s.size()) {
            if (count == 3) res = true;
        } else {
            if (ispar(s, l, r)) { // 这部分是回文串
                // 分割
                dfs(s, r + 1, r + 1, count + 1);
                // 或者不分割
                dfs(s, l, r + 1, count);
            } else { // 这部分不是回文串
                // 只能不分割
                dfs(s, l, r + 1, count);
            }
        }
    }
    bool checkPartitioning(vector<char> &s) {
        // write code here
        res = false;
        dfs(s, 0, 0, 0);
        return res;
    }
};

int main() {
    //
    Solution so;
    vector<char> s = {'b', 'c', 'b', 'd', 'd', 'x', 'y'};
    bool ans = so.checkPartitioning(s);
    cout << ans;
    return 0;
}