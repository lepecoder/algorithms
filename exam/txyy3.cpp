#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param k int整型
     * @return long长整型
     */
    friend void Time(const Solution a, const Solution b);
    long long minM(int n, int k) {
        // k进制，1-m出现了n个1

        // k进制 1-n中1出现的次数
        // 计算k进制下n有多少位
        // k进制m位最多包含0-k^m-1
        int m = 1;
        while (pow(k, m) - 1 < n) m++;
        return 1;
    };

  protected:
    int a;

  private:
    char ccc;
    friend void Time(const Solution a, const Solution b) { a.ccc; }
    int main() {
        //
        Solution so;
        so.a;
        return 0;
    }