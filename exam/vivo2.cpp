#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型 未来空闲工作日
     * @return int整型
     */
    int res = 0;
    void fun(int k) {
        if (k == 0) {
            res++;
            return;
        }
        if (k >= 1) fun(k - 1);
        if (k >= 2) fun(k - 2);
        if (k >= 4) fun(k - 4);
    }
    int workSchedule(int n) {
        // write code here
        fun(n);
        return res;
    }
};
int main() {
    //
    return 0;
}