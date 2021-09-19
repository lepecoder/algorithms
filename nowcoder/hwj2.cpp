#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m; // 列表长度为N，M个操作
void fun(ll diff[], int a, int b, int k) {
    // a b之间的元素增加k
    diff[a] += k;
    diff[b + 1] -= k;
}
void cal(ll arr[], ll diff[]) {
    for (int i = 1; i <= n; i++) { arr[i] = arr[i - 1] + diff[i]; }
}
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;

int main() {
    //
    cin >> n >> m;
    ll arr[n + 1];
    ll diff[n + 2]; // 差分数组
    // diff[1] = arr[1]-arr[0];
    // arr[1] = arr[0]+diff[1];
    memset(arr, 0, sizeof(arr));
    memset(diff, 0, sizeof(diff));
    int a, b, k;
    while (m--) {
        cin >> a >> b >> k;
        fun(diff, a, b, k);
        // cal(arr, diff);
        // show(arr, 1, n + 1);
    }
    cal(arr, diff);
    // int res = max_element(arr+1, arr+n+1);
    ll res = arr[1];
    // show(arr, 1, n + 1);
    for (int i = 2; i <= n; i++) { res = max(res, arr[i]); }
    cout << res;

    return 0;
}