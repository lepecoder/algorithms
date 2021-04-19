#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        /* 摩尔投票
        当有一个人的票数超过所有票数的一半时
        可以采用不同阵营投票人两两抵消的方式
        那么如果有一个票数超过总票数的一半，他一定是最后剩下的
         */
        int n = nums.size();
        int num = nums[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == num) {
                count++;
            } else {
                if (--count == 0) {
                    num = nums[i];
                    count = 1;
                }
            }
        }
        return num;
    }
};
int main() {
    //
    return 0;
}