#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
  public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     *
     * 最大正整数
     * @param arrs int整型vector 正整数数组
     * @return int整型
     */
    int maxIntValue(vector<int> &arrs) {
        // write code here
        sort(arrs.begin(), arrs.end(), greater<int>());
        int res = 0;
        for (int i = 0; i < arrs.size(); i++) { res = res * 10 + arrs[i]; }
        return res;
    }
};

int main() {
    //
    return 0;
}