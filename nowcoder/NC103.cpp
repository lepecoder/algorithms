#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /**
     * 反转字符串
     * @param str string字符串
     * @return string字符串
     */
    string solve(string str) {
        // write code here
        int l = 0, r = str.size() - 1;
        while (l < r) {
            swap(str[l], str[r]);
            ++l;
            --r;
        }
        return str;
    }
};
int main() {
    //
    return 0;
}