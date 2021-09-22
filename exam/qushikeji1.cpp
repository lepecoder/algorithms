#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //
    int n, k;
    cin >> n >> k;
    int t;
    unordered_set<int> st;
    for (int i = 0; i < k; i++) {
        cin >> t;
        st.emplace(t);
    }

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (st.count(i) == 0) {
            dp[i] = dp[i - 1];
            if (i - 2 >= 0) dp[i] += dp[i - 2];
            //  dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    cout << dp[n];

    return 0;
}