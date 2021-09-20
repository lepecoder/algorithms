#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
  public:
    int getMaxSubstrLenProd(string inputStr) {
        // write code here
        int n = inputStr.size();
        bool alpha1[333];
        // bool alpha2[333];
        // int pos[n];
        int max1 = 0, max2 = 0;
        int res = 0;
        int i, j, k;
        for (i = 0; i < n; i++) {
            // 从i开始
            memset(alpha1, false, sizeof(alpha1));
            for (j = i; j < n; j++) {
                max1 = j + i + 1;
                alpha1[inputStr[j]] = true;
                int left = j + 1;
                max2 = 0;
                for (k = j + 1; k < n; k++) {
                    // 在j之后找最大的连续区域，不包含alpha1里的字符
                    char c = inputStr[k];
                    if (alpha1[inputStr[k]] == true || k == n - 1) { // 出现过
                        max2 = max(max2, k - left);
                        left = k + 1;
                    }
                }
                if (max1 * max2 > res) {
                    cout << max1 << "*" << max2 << "=" << (max1 * max2) << endl;
                    for (int t = j; t < j + max1 && t < n; t++) cout << inputStr[t];
                    cout << "   , ";
                    for (int t = left; t < left + max2 && t < n; t++) cout << inputStr[t];
                    cout << endl;
                    cout << "i=" << i << ", j=" << j << ", k=" << k << endl;
                }
                res = max(res, max1 * max2);
            }
        }
        return res;
    }
};
int main() {
    //
    string inputStr = "adcbadcbedbadedcbacbcadbc";
    Solution so;
    int ans = so.getMaxSubstrLenProd(inputStr);
    cout << ans;
    return 0;
}