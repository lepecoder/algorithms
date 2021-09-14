#include <bits/stdc++.h>
using namespace std;
#define ll long long

//
int _IO = []() {
    std::ios::sync_with_stdio(0);
    cin.tie(0); // cout.tie(0);
    return 0;
}();
int ans = 0;
void install(int x, bool bs[], int a[]) {
    if (bs[x] == true) return;
    ans++;
    bs[x] = true;
    install(a[x], bs, a);
}
void uninstall(int x, bool bs[], vector<vector<int>> &uni) {
    if (bs[x] == false) return;
    ans++;
    bs[x] = false;
    for (int &e : uni[x]) { uninstall(e, bs, uni); }
}

int main() {
    //
    int n;
    cin >> n;
    int a[n];
    vector<vector<int>> uni(n, vector<int>());
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        uni[a[i]].emplace_back(i);
    }
    int q;
    cin >> q;
    string s;
    int x;
    bool bs[n];
    int pre = 0;
    memset(bs, false, sizeof(bs));
    while (q--) {
        cin >> s >> x;
        int res;
        if (s == "install") {
            ans = 0;
            install(x, bs, a);
            cout << ans << endl;
        } else {
            ans = 0;
            uninstall(x, bs, uni);
            cout << ans << endl;
        }
    }
    return 0;
}