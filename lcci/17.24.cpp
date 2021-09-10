#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;
class Solution {
  public:
    vector<int> getMaxMatrix(vector<vector<int>> &matrix) {

        int m = matrix.size(), n = matrix[0].size();
        int maxMat = INT_MIN;
        vector<int> ans(4, -1);
        // 二维的最大子序和
        // 二维矩阵两行间压缩
        for (int r1 = 0; r1 < m; ++r1) {      //遍历起始行
            vector<int> nums(n);              //矩阵某两行间元素按列求和
            for (int r2 = r1; r2 < m; ++r2) { //遍历结束行
                //最大字段和问题
                int dp = 0, start = -1;
                for (int i = 0; i < n; ++i) { //遍历和数组，实际上是边遍历边完成求和
                    // nums[i]累加求和
                    nums[i] += matrix[r2][i]; //将新的一行中第i个元素加到前面若干行在位置i的和
                    if (dp > 0) {             //前面的字段有和为正，可以把前面一部分也带上
                        dp += nums[i];
                    } else { //前面一段为负，拖后腿直接抛弃
                        dp = nums[i];
                        start = i;
                    }
                    if (dp > maxMat) { //不断记录较好的结果
                        maxMat = dp;
                        ans = {r1, start, r2, i};
                    }
                }
            }
        }
        return ans;
    }
};
int main() {
    //
    return 0;
}