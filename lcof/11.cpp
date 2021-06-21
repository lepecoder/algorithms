#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minArray(vector<int> &numbers) {
        int l = 0, r = numbers.size() - 1;
        int m;
        while (l < r) {
            if (numbers[l] < numbers[r]) { // 单调的，最左就是最小值
                return numbers[l];
            } else { // 中间有旋转
                m = (l + r) / 2;
                if (numbers[m] > numbers[r]) { // 分割点在右侧
                    l = m + 1;
                } else if (numbers[m] == numbers[r]) {
                    --r;
                } else {
                    r = m;
                }
            }
        }
        return numbers[l];
    }
};
int main() {
    //
    return 0;
}