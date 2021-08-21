#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回Sn的第k位字符
     * @param n int整型 Sn的n
     * @param k int整型 需要返回的字符下标位
     * @return char字符型
     */
    char findKthBit(int n, int k) {
        // write code here
        /*
        Sn 的长度是 2*S{n-1} + 1
        补充的额外是n + 27-(Sn)
         */
        int lenN = 1; // Sn的长度
        // int cur = 1;  // 当前结果数字
        int curN = 1; // Sn的n计数
        vector<int> cur;
        cur.emplace_back(1);
        for (int i = 1; i < k; i++) {
            if (i == lenN) {
                for (int &x : cur) {
                    char c = 'a' + x - 1;
                    cout << c;
                }
                cout << endl;
                lenN = 2 * lenN + 1;
                curN++;
                cur.emplace_back(curN);
                for (int i = cur.size() - 2; i >= 0; i--) {
                    int t = cur[i];
                    cur.emplace_back(27 - t);
                }
            }
        }
        return 'a' + cur[k - 1] - 1;
    }
};
int main() {
    //
    Solution so;
    char c = so.findKthBit(4, 9);
    cout << c << endl;
    return 0;
}