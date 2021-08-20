#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int x;
    int t;
    while (cin >> n) {
        priority_queue<int> q;
        int res = 0;
        cin >> x;
        for (int i = 0; i < n - 1; i++) {
            cin >> t;
            q.emplace(t);
        }
        while (true) {
            t = q.top();
            q.pop();
            if (t < x) {
                cout << res << endl;
                break;
            } else {
                ++x;
                ++res;
                --t;
                q.emplace(t);
            }
        }
    }
    return 0;
}