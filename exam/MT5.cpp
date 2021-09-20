#include <bits/stdc++.h>
using namespace std;

int main() {
    // n个数中找到长度m的连续子区间
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    // queue<int> qmin,qmax;
    stack<int> smin; // 保存窗口最小值
    // queue<int> qmin;  // 保存窗口最小值
    deque<int> qmin;
    deque<int> qmax;
    int sum = 0;
    int res = 1;
    for (int i = 0; i < n && i < m; i++) {
        int x = a[i];
        sum += x;
        while (!qmin.empty() && qmin.back() > x) { qmin.pop_back(); }
        qmin.emplace_back();
        while (!qmax.empty() && qmax.back() < x) { qmax.pop_back(); }
        qmax.emplace_back();
    }
    for (int i = m; i < n; i++) {
        int x = a[i];
        int _awldj;
        sum += x;
    }
    return 0;
}