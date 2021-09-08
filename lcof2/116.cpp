#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x, idx, n)                                                                                                                                        \
    for (int i = idx; i < n; i++) cout << x[i] << ' ';                                                                                                         \
    cout << endl;

class Solution {
  public:
    int *fa;
    int find(int idx) {
        if (fa[idx] == idx) { return idx; }
        return fa[idx] = find(fa[idx]);
    }
    void unin(int i, int j) {
        int fi = find(i);
        int fj = find(j);
        if (fi != fj) fa[i] = fa[j];
    }
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        fa = new int[n];
        for (int i = 0; i < n; i++) fa[i] = i; // 自己的父代
        // for (auto &v : isConnected) {
        // if (v[2] == 1) { fa[v[0]] = v[1]; }
        // }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) unin(i, j);
            }
        }
        bool res[n];
        memset(res, false, sizeof(res));
        for (int i = 0; i < n; i++) {
            int x = find(i);
            res[x] = true;
        }
        for (int i = 0; i < n; i++) cout << fa[i] << ' ';
        cout << endl;
        return accumulate(res, res + n, 0);
    }
};
int main() {
    // int a;
    vector<int> v = {1, 2, 3};
    show(v, 0, 3);
    return 0;
}