#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    bool fun(vector<int> &a, vector<int> &b) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] <= b[i]) { return false; }
        }
        return true;
    }
    int pareto(vector<int> &a, vector<int> &b) {
        // 如果a支配b，返回1，
        // 如果b支配a，返回-1；
        // 非支配关系，返回0
        if (fun(a, b)) return 1;
        if (fun(b, a)) return -1;
        return 0;
    }
    int maxRollingHeroes(vector<vector<int>> &heroes) {
        // write code here
        int n = heroes.size();
        int k = heroes[0].size();
        vector<vector<int>> edge(n, vector<int>());
        int indegree[n];
        memset(indegree, 0, sizeof(indegree));
        int a[n];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int t = pareto(heroes[i], heroes[j]);
                if (t == 1) {
                    a[i]++;
                    edge[i].emplace_back(j);
                    indegree[j]++;
                }
            }
        }
        int sum_ = 0;
        for (int i = 0; i < n; i++) {
            sum_ += a[i];
            // cout << a[i] << ',';
        }
        if (sum_ == 0) return 0;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.emplace(i);
        }
        int res = 0;
        while (!q.empty()) {
            int count = q.size();
            res++;
            while (count--) {
                int t = q.front();
                q.pop();
                for (int x : edge[t]) {
                    indegree[x]--;
                    if (indegree[x] == 0) { q.emplace(x); }
                }
            }
        }
        return res;
    }
};
int main() {
    //
    return 0;
}