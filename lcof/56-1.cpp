#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> singleNumbers(vector<int> &nums) {
        /* 除了两个数字外，其它数字都出现了两次，
        假设只有一个数字出现了一次，可以很容易的对所有数字异或得到
        所以我们可以对数字分组，使得
        1. 两个只出现一次的数字在不同的组中；
        2. 相同的数字会被分到相同的组中。
        对所有数字进行异或，最后的结果一定不等于0
        找到它为1的位，根据这一位对数字进行分组，
        一定可以做到，a b分到不同分组，而且相XMMTUyMzg0MDAwMF8zNQ==同数字分到同一分组 */
        int res = 0;
        for (int &e : nums) res ^= e;
        int div = 1;
        while ((div & res) == 0) {
            //
            div <<= 1;
        } // 找到不为0的位
        int a = 0, b = 0;
        for (int &e : nums) {
            if ((e & div)) {
                a ^= e;
            } else {
                b ^= e;
            }
        }
        return {a, b};
    }
};
int main() {
    Solution so;
    vector<int> nums{1, 2, 5, 2};
    auto ans = so.singleNumbers(nums);
    return 0;
}