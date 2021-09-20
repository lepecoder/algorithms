#include <bits/stdc++.h>
using namespace std;

int main() {
    /* 在主角的攻击击穿时会恢复溢出的生命值 */
    /* 主角任何时刻生命值不能为0 */
    int _IO = []() {
        std::ios::sync_with_stdio(0);
        cin.tie(0); // cout.tie(0);
        return 0;
    }();
    int T;
    int n;    //怪物数量
    int A, B; //主角的攻击力和防御力
    int H;    // 主角生命值
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> A >> B;
        int a[n], b[n], h[n];
        for (int i = 0; i < n; i++) { cin >> a[i] >> b[i] >> h[i]; }
        /* 最后的生命值至少是1 */
        H = 1;
        int modh = h[n - 1] % (A - b[n - 1]);
        int addh = A - b[n - 1] - modh;
        H += addh;
        for (int i = n - 1; i >= 0; i--) {
            if (A <= b[i]) { // 如果主角的攻击力<=怪物的防御力，无法通关
                H = -1;
                break;
            }
            while (h[i] > 0) {
                h[i] -= max(A - b[i], 0); // 主角攻击
                if (h[i] <= 0) {          // 怪物死了
                    H -= -h[i];           // 主角恢复生命
                    H = max(H, 1);        // 任何时刻至少1血量
                    break;
                }
                H += max(a[i] - B, 0); // 怪物攻击
            }
        }
        // if (H == -1) { // 主角打不过
        // cout << -1 << endl;
        // } else {
        cout << H << endl;
        // }
    }

    return 0;
}