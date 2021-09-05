#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll res = 0;
    deque<int> de;
    int min1, min2, right, left;
    for (int i = 0; i < n - 1; i++) {
        res++;                      // 长度为2一定是有效序列
        min1 = min(a[i], a[i + 1]); // 最小值
        min2 = max(a[i], a[i + 1]); // 次小值
        left = a[i];
        // cout << "left = " << left << endl;
        // cout << "        right: ";
        for (int j = i + 2; j < n; j++) {
            right = a[j];
            /* 下列是否有=需要考量 */
            if (right > min2) { //
                continue;
            } else if (right == min2) {
                if (left == min1) res++;
            } else if (right < min2 && right > min1) {
                if (left == min1) { res++; }
                min2 = right;
            } else if (right == min1) {
                // 需要更新次小值
                min2 = min1;
                if (left == min1) res++;
            } else if (right < min1) {
                if (left == min1) res++;
                // 需要更新次小和最小
                min2 = min1;
                min1 = right;
            }
            // cout << "   right=" << right << ", res=" << res;
            if (left > min2) break;
        }
        // cout << endl;
    }
    cout << res;
    return 0;
}