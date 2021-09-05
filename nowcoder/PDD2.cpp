#include <bits/stdc++.h>
using namespace std;

void backtrack(string s) {}
bool cmp(const string &a, const string &b) {
    /* 要使得某一形态a小于b的所有形态，即最小形态a小于b的最小形态 */
    string c = a;
    int n = c.size();
    for (int i = 0; i < n / 2; i++) {
        if (c[i] > c[n - 1 - i]) { swap(c[i], c[n - 1 - i]); }
    }
    string d = b;
    int m = d.size();
    for (int i = 0; i < m / 2; i++) {
        if (d[i] > d[m - 1 - i]) { swap(d[i], d[n - 1 - i]); }
    }
    return c < d;
}

int main() {
    //
    int n;
    cin >> n;
    string tmp_s;
    vector<string> vec_s;
    vec_s.reserve(n);
    for (int i = 0; i < n; i++) {
        cin >> tmp_s;
        vec_s.emplace_back(tmp_s);
    }
    stable_sort(vec_s.begin(), vec_s.end(), cmp);
    for (auto &s : vec_s) { cout << s << endl; }
    return 0;
}