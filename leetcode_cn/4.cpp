#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size();
        int k = n + m;
        if (k % 2 == 1) return findMedianSortedArrays1(nums1, nums2, (n + m + 1) / 2);
        return (findMedianSortedArrays1(nums1, nums2, k / 2) + findMedianSortedArrays1(nums1, nums2, k / 2 + 1)) / 2;
    }

    double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        // int k = (n+m)/2;
        int l = 0, r = 0;
        while (true) {
            if (l == n) { return nums2[r + k - 1]; }
            if (r == m) { return nums1[l + k - 1]; }
            if (k == 1) { return min(nums1[l], nums2[r]); }
            int lidx = min(l + k / 2, n) - 1;
            int ridx = min(r + k / 2, m) - 1;
            if (nums1[lidx] < nums2[ridx]) {
                k -= lidx - l + 1;
                l = lidx + 1;
            } else {
                k -= ridx - r + 1;
                r = ridx + 1;
            }
        }
    }
};
int main() {
    //
    int n;

    return 0;
}