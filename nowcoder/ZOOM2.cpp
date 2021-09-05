#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    string join;
    cin >> join;
    string res;
    int idx = join.size();
    for (int i = 0; i < join.size() - 4; i++) {
        if (join[i] == '/' && join[i + 2] == '/' && (join[i + 1] == 'j' || join[i + 1] == 'w' || join[i + 1] == 's')) {
            idx = i + 3;
            break;
        }
    }
    if (idx < join.size() - 4) {
        for (int i = idx; i < join.size(); i++) {
            if (join[i] >= '0' && join[i] <= '9') {
                res += join[i];
            } else {
                break;
            }
        }
    }
    if (res.size() >= 9 && res.size() <= 11) {
        istringstream ss(res);
        long long ll;
        ss >> ll;
        cout << ll;
    } else {
        cout << 0;
    }
    return 0;
}