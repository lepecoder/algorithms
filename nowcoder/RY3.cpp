#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int m; // 处理器个数
    int n; // 作业数量
    int t;
    priority_queue<int, vector<int>, greater<int>> q1;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        q1.emplace(t);
    }
    // cout << q.top() << endl;
    priority_queue<int, vector<int>, greater<int>> q2;
    priority_queue<int, vector<int>, greater<int>> q3;
    while (!q1.empty() && q2.size() < m) {
        t = q1.top();
        q2.emplace(t);
        q1.pop();
    }
    int res = 0;
    while (!q1.empty()) {
        int minq = q2.top();
        res += minq;
        q2.pop();
        priority_queue<int, vector<int>, greater<int>> q3;
        while (!q2.empty()) {
            t = q2.top();
            q2.pop();
            q3.emplace(t - minq);
        }
        q2 = q3;
        t = q1.top();
        q1.pop();
        q2.emplace(t);
    }

    // q2里还有剩余任务
    if (!q2.empty()) {
        int maxq = q2.top();
        while (!q2.empty()) {
            maxq = max(maxq, q2.top());
            q2.pop();
        }
        res += maxq;
    }
    cout << res << endl;
    return 0;
}