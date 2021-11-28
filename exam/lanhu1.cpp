#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int weight[n];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) { pq.emplace(arr[i]); }
    int ans = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a + b;
        ans += c;
        pq.emplace(c);
    }
    // ans += pq.top();
    cout << ans;

    return 0;
}