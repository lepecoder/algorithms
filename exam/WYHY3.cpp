#include <bits/stdc++.h>
using namespace std;

int n, m, q, L;
double getV(int hei[], double h) {
    // 水位高度h时，假山占用的体积
    double res = 0;
    for (int i = 0; i < n * m; i++) {
        if (h >= hei[i]) {
            res += hei[i] / 3.0;
        } else {
            /* 此时是四棱台 */
            double toph = hei[i] - h;
            double x = toph / hei[i];
            double v = h * (x * x + 1 + x) / 3;
            res += v;
        }
    }
    // 水的体积 = 总体积-假山体积
    res = n * m * h - res;
    return res;
}

int main() {
    //  可以用二分搜索试试
    int _IO = []() {
        std::ios::sync_with_stdio(0);
        cin.tie(0); // cout.tie(0);
        return 0;
    }();
    cin >> n >> m;
    int hei[n * m];
    string line;
    getline(cin, line);
    getline(cin, line);
    istringstream ss(line);
    int k = 0;
    int t;
    while (ss >> hei[k]) { k++; }
    // for (int i = 0; i < n * m; i++) { ss >> hei[i]; }
    // for (int i = 0; i < n * m; i++) { cin >> hei[i]; }
    cin >> q;
    double res;
    while (q--) {
        cin >> L;
        double maxh = 7000;
        double minh = 0;
        double midh;
        double V;
        while (minh < maxh) {
            midh = minh + (maxh - minh) / 2;
            V = getV(hei, midh); // 水位高度midh时水的体积
            if (abs(V - L) < 0.001) {
                minh = midh;
                break;
            }
            if (V > L) {
                maxh = midh - 0.0001;
            } else {
                minh = midh + 0.0001;
            }
        }
        cout.setf(ios::fixed);
        cout << fixed << setprecision(4) << minh << endl;
    }

    return 0;
}