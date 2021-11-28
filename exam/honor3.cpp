#include <bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<string, char> mp;
string in;
string alphabet[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int acount[26];
string ans;

void dfs(int acount[26], string path) {
    int res = 0;
    for (int i = 0; i < 26; i++) { res += acount[i]; }
    if (res == 0) {
        ans = path;
        return;
    }
    int idx;
    for (idx = 0; idx < 10; idx++) { if () }
}
int main() {
    cin >> in;
    memset(acount, 0, sizeof(acount));
    int n = in.size();
    transform(in.begin(), in.end(), in.begin(), ::tolower);
    for (char c : in) { acount[c - 'a']++; }

    return 0;
}