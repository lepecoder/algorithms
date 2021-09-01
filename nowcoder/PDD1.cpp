#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int T;
    cin >> T;
    int n, m, k;
    while (T--) {
        cin >> n >> m >> k;
        int red[n];
        int blue[m];
        for (int i = 0; i < n; i++) cin >> red[i];
        for (int i = 0; i < m; i++) cin >> blue[i];
        sort(red, red + n);
        sort(blue, blue + m);
        int num = 0;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (red[i] > blue[j] && red[i] - blue[j] <= k) {
                i++;
                j++;
                num++;
            } else if (red[i] > blue[j] && red[i] - blue[j] > k) {
                j++;
            } else if (red[i] < blue[j] && blue[j] - red[i] <= k) {
                i++;
                j++;
                num++;
            } else if (red[i] < blue[j] && blue[j] - red[i] > k) {
                i++;
            } else if (red[i] == blue[j]) {
                i++;
                j++;
                num++;
            }
        }
        cout << num << endl;
    }
    return 0;
}
