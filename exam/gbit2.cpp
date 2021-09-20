#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
void dfs(int x, bool vis[], vector<vector<int>> &edg) {
    if (vis[x] == true) return;
    vis[x] = true;
    for (int &e : edg[x]) { dfs(e, vis, edg); }
}

void Prim(int n, vector<vector<int>> &edge) {
    int lowcost[n + 1]; //存储S中到达对应的其它各点的最小权值分别是多少
    int closest[n + 1]; // closest[]数组保存的是未在S中的点所到达S中包含的最近的点是哪一个,如:closest[i]=1表示i最靠近的S中的点是1
    bool s[n + 1]; // bool型变量的S数组表示i是否已经包括在S中
    memset(s, false, sizeof(s));
    int i, k;
    // s[0]=true;//从第一个结点开始寻找,扩展
    s[1] = true;
    for (int &x : edge[1]) {}
    for (i = 1; i <= n; i++) //简单初始化
    {
        lowcost[i] = c[0][i];
        closest[i] = 0; //现在所有的点对应的已经在S中的最近的点是1
        s[i] = false;
    }
    cout << "0->";
    for (i = 0; i < n; i++) {
        int min = 1000; //最小值,设大一点的值,后面用来记录lowcost数组中的最小值
        int j = 1;
        for (k = 1; k <= n; k++) //寻找lowcost中的最小值
        {
            if ((lowcost[k] < min) && (!s[k])) {
                min = lowcost[k];
                j = k;
            }
        }
        cout << j << " "
             << "->";
        s[j] = true;             //添加点j到集合S中
        for (k = 1; k <= n; k++) //因为新加入了j点,所以要查找新加入的j点到未在S中的点K中的权值是不是可以因此更小
        {
            if ((c[j][k] < lowcost[k]) && (!s[k])) {
                lowcost[k] = c[j][k];
                closest[k] = j;
            }
        }
    }
}
int main() {
    //
    cin >> n >> m;
    // vector<vector<pair<int,int>>> edge(n, vector<pair<int,int>>());
    vector<vector<int>> edge(n, vector<int>());
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    int mat[n + 1][n + 1];
    memset(mat, 0x3f, sizeof(mat));
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        mat[a][b] = mat[b][a] = c;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    dfs(1, vis, edge);
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            cout << -1;
            return 0;
        }
    }
    memset(vis, false, sizeof(vis));

    return 0;
}