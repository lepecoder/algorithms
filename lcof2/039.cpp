#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        /* 直方图矩形的最大面积和接雨水刚好是相反的
        对于一个柱，我们需要找到它的左侧第一个小于它的柱形和右侧第一个小于它的柱形
        之后围成的面积就是高度为heights[i]的最大矩形的面积
         */

        int n = heights.size();
        int left[n];  // left[i]保存i左侧小于heights[i]的下标，没有就-1
        int right[n]; // right[i]保存i右侧小于heights[i]的下标，没有置为-1
        memset(left, -1, sizeof(left));
        memset(right, -1, sizeof(right));
        stack<int> st1;
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && heights[st1.top()] > heights[i]) {
                left[st1.top()] = i;
                st1.pop();
            }
            st1.emplace(i);
        }
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.emplace(i);
        }
        // show(left, 0, n);
        // show(right, 0, n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int l = left[i];
            int r = right[i];
            if (r == -1) r = n;
            res = max(res, heights[i] * (r - l - 1));
        }

        return res;
    }
};
int main() {
    //
    Solution so;
    vector<int> hei = {2, 1, 5, 6, 2, 3};
    so.largestRectangleArea(hei);
    return 0;
}