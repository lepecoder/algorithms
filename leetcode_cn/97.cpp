/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    string s1, s2, s3;
    int arr[110][110];
    bool dp(int idx1, int idx2) {
        /* 判断s1的前idx1个字符和s2的前idx2个字符是否能构成
        s3的前idx1+idx2个字符，不包含边界
        */
        if (idx1 < 0 || idx2 < 0) return false;
        if (arr[idx1][idx2] != 0) return arr[idx1][idx2] == 1;
        bool b1 = false, b2 = false;
        if (s1[idx1 - 1] == s3[idx1 + idx2 - 1]) { b1 = dp(idx1 - 1, idx2); }
        if (s2[idx2 - 1] == s3[idx1 + idx2 - 1]) { b2 = dp(idx1, idx2 - 1); }
        if (b1 || b2) {
            arr[idx1][idx2] = 1;
        } else {
            arr[idx1][idx2] = -1;
        }
        return b1 || b2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        if (n1 + n2 != n3) return false;
        memset(arr, 0, sizeof(arr));
        arr[0][0] = 1;

        bool res = dp(n1, n2);
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) { cout << arr[i][j] << ' '; }
            cout << endl;
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    bool res = so.isInterleave(s1, s2, s3);
    cout << res;
    return 0;
}