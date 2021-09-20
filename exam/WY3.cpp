#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long int t;
    vector<long long int> a;
    while (cin >> t) { a.emplace_back(t); }
    int n = a.size();
    vector<long long int> paper(n, 1);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) { paper[i + 1] = paper[i] + 1; }
    }
    if (a[n - 1] < a[0]) { paper[0] = max(paper[0], paper[n - 1] + 1); }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) { paper[i] = max(paper[i], paper[i + 1] + 1); }
    }
    if (a[n - 1] > a[0]) { paper[n - 1] = max(paper[n - 1], paper[0] + 1); }

    long long int res = accumulate(paper.begin(), paper.end(), 0);
    cout << res;

    return 0;
}