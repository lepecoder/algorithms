#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int T;
    int n;
    int precount;
    int t;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> indeg;         // 入度
        vector<vector<int>> edges; // u->v  连接的边
        vector<int> times;         // 每个任务的时间
        vector<int> pretimes;      // 每个任务的前置任务最大时刻
        vector<int> complete;      // 每个任务的完成时刻
        indeg.resize(n);
        edges.resize(n);
        times.resize(n);
        pretimes.resize(n);
        complete.resize(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            cin >> times[i];
            cin >> precount;
            indeg[i] = precount; // 任务i有precount个入度
            if (precount == 0) { // 没有前置任务
                q.emplace(i);
                pretimes[i] = 0;
            }
            while (precount--) {
                cin >> t;
                edges[t - 1].emplace_back(i); // 第t个任务是第i个任务的前置条件
            }
        }
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                int u = q.front();
                complete[u] = pretimes[u] + times[u];
                q.pop();
                for (int &v : edges[u]) { // u->v
                    indeg[v]--;
                    pretimes[v] = max(pretimes[v], complete[u]);
                    if (indeg[v] == 0) { q.emplace(v); }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, complete[i]);
            // cout << complete[i] << ' ';
        }
        // cout << endl;
        // for (int i = 0; i < n; i++) { cout << pretimes[i] << ' '; }
        // cout << endl;
        cout << res << endl;
    }
    return 0;
}