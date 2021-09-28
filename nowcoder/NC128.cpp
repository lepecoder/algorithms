#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int> &arr) {
        // write code here
        int n = arr.size();
        int left[n];
        int right[n];
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        left[0] = arr[0];
        for (int i = 1; i < n; i++) { left[i] = max(arr[i], left[i - 1]); }
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) { right[i] = max(right[i + 1], arr[i]); }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int t = min(left[i], right[i]) - arr[i];
            res += t;
        }
        return res;
    }
};
int main() {
    //
    return 0;
}