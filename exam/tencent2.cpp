#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<ll>());
    unordered_set<ll> st;
    for (int i = 0; i < n; i++) {
        ll t = arr[i] * arr[i];
        // if (t == 1) continue;
        if (st.count(t) > 0) {
            cout << arr[i] << ' ' << t;
            return 0;
        }
        st.emplace(arr[i]);
    }
    cout << -1;

    return 0;
}