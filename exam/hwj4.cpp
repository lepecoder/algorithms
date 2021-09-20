#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;
int res = 0;
int n;
void fun(vector<int> &arr, int idx, int x) {
    // 当前的索引是idx，它的值是x
    // 如果idx==x 直接结束
    if (idx == x) return;
    res++;
    // 否则, 把x调整到x的位置
    swap(arr[idx], arr[x]);
    // 此时arr[idx]被调整到了合适的位置
    // 但是当前位置idx又不对了
    // show(arr, 0, n);
    fun(arr, idx, arr[idx]);
}
int main() {
    //
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    vector<int> arr2(arr);
    vector<int> arr3(arr);
    sort(arr2.begin(), arr2.end());
    unordered_map<int, queue<int>> mp(n);
    for (int i = 0; i < n; i++) { mp[arr2[i]].emplace(i); }
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        arr[i] = mp[x].front();
        mp[x].pop();
    }
    // show(arr2, 0, n);
    // show(arr, 0, n);
    for (int i = 0; i < n; i++) { fun(arr, i, arr[i]); }
    int ans = res;
    // cout << res;
    // cout << endl;

    sort(arr2.begin(), arr2.end(), greater<int>());
    unordered_map<int, queue<int>> mp1(n);

    for (int i = 0; i < n; i++) { mp1[arr2[i]].emplace(i); }
    for (int i = 0; i < n; i++) {
        int x = arr3[i];
        arr3[i] = mp1[x].front();
        mp1[x].pop();
    }
    // cout << res;
    // show(arr2, 0, n);
    // show(arr3, 0, n);
    res = 0;
    for (int i = 0; i < n; i++) { fun(arr3, i, arr3[i]); }
    // cout << res;
    // cout << endl;
    cout << min(ans, res);

    return 0;
}