#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    ll k;
    int n;
    cin >> n >> k;
    ll t;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < n; i++) {
        cin >> t;
        q.emplace(t);
    }
    int res = 0;
    while (!q.empty() && q.top() < k) {
        res++;
        ll x = q.top();
        q.pop();
        ll y;
        if (q.empty()) {
            y = x;
        } else {
            y = q.top();
            q.pop();
        }
        ll z = x + 2 * y;

        q.emplace(z);
    }
    cout << res;

    return 0;
}