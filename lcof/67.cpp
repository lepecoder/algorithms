#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int strToInt(string str) {
        int res = 0;
        int i = 0;
        int length = str.size();
        int sign = 1;
        int bndry = INT32_MAX / 10;
        // 去除空格
        while (str[i] == ' ') {
            if (++i == length) return 0;
        }
        if (str[i] == '-') sign = -1;
        if (str[i] == '-' || str[i] == '+') i++;
        for (; i < length; i++) {
            if (str[i] < '0' || str[i] > '9') break;
            if (res > bndry || res == bndry && str[i] > '7') { return sign == 1 ? INT32_MAX : INT32_MIN; }
            res = res * 10 + (str[i] - '0');
        }
        return sign * res;
    }
};
int main() {
    //
    return 0;
}