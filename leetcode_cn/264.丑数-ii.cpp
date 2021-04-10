#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long nthUglyNumber(int n) {
        // 丑数一定是2^a*3^b*5^c
        // 初始a=b=c=0
        // 利用合并3个有序链表的思想递增abc
        long res = 1;
        int count = 1;
        set<long> heap;
        heap.insert(1);
        while (count++ < n) {
            auto it = heap.begin();
            heap.insert((*it) * 2);
            heap.insert((*it) * 3);
            heap.insert((*it) * 5);
            heap.erase(heap.begin());
        }
        return (*heap.begin());
    }
};

int main() {
    Solution so;
    long ans = so.nthUglyNumber(1);
    cout << ans;
    return 0;
}