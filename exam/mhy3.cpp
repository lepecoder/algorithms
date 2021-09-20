#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(pair<int, int> &p) {
    if (p.first >= 0 && p.first < 10 && p.second >= 0 && p.second < 9) { return true; }
    return false;
}

pair<int, int> top(pair<int, int> &p) {
    pair<int, int> res(p);
    res.first -= 1;
    if (check(res)) { return res; }
    return {-1, -1};
}
pair<int, int> top(pair<int, int> &p) {}

int main() {
    //
    int dir1[5] = {0, 1, 0, -1, 0};
    int dir2[5] = {1, 1, -1, -1, 1};
    int n = 10, m = 9;
    int board[n][m];
    memset(board, 0, sizeof(board));
    pair<int, int> xiang;
    pair<int, int> jiang;
    cin >> xiang.first >> xiang.second;
    cin >> jiang.first >> jiang.second;
    map<pair<int, int>, int> mp;
    mp[xiang] = 0;
    queue<pair<int, int>> q;
    q.emplace(xiang);
    while (!q.empty()) {
        int count = q.size();
        while (count--) {
            pair<int, int> t = q.front();
            q.pop();
            for (int d1 = 0; d1 < 4; d1++) {
                pair<int, int> t1(t);
                t1.first += dir1[d1];
                t1.second += dir1[d1 + 1];
                if (t1 == jiang) continue;
                if (d1 == 0) { // top
                    for (int k = 0; k < 2; k++) {
                        if (k == 0) { // left
                            pair<int, int> t2(t1);
                            t2.second += 1;
                            t2.first -= 1;
                            if (t2 == jiang) continue;
                            t2.second += 1;
                            t2.first -= 1;
                            if (check(t2) == false) continue;
                            // 到达新位置
                            if (mp.count(t2) == 0) {
                                mp[t2] = mp[t] + 1;
                                // if (t2==jiang)
                                q.emplace(t2);
                            }
                        }
                        if (k == 1) { // right
                            pair<int, int> t2(t1);
                            t2.second += 1;
                            t2.first += 1;
                            if (t2 == jiang) continue;
                            t2.second += 1;
                            t2.first += 1;
                            if (check(t2) == false) continue;
                            // 到达新位置
                            if (mp.count(t2) == 0) {
                                mp[t2] = mp[t] + 1;
                                // if (t2==jiang)
                                q.emplace(t2);
                            }
                        }
                    }
                }
                if (d1 == 1) { // right
                    for (int k = 0; k < 2; k++) {
                        if (k == 0) { // top
                            pair<int, int> t2(t1);
                            t2.first += 1;
                            t2.second += 1;
                            if (t2 == jiang) continue;
                            t2.first += 1;
                            t2.second += 1;
                            // 到达新位置
                            if (mp.count(t2) == 0) {
                                mp[t2] = mp[t] + 1;
                                q.emplace(t2);
                            }
                        }
                        if (k == 1) { // down
                            pair<int, int> t2(t1);
                            t2.first += 1;
                            t2.second -= 1;
                            if (t2 == jiang) continue;
                            t2.first += 1;
                            t2.second -= 1;
                            if (check(t2) == false) continue;
                            // 到达新位置
                            if (mp.count(t2) == 0) {
                                mp[t2] = mp[t] + 1;
                                q.emplace(t2);
                            }
                        }
                    }
                }
                if (d1 == 2) { // down
                    for (int k = 0; k < 2; k++) {
                        if (k == 0) { // left
                            pair<int, int> t2(t1);
                            t2.first -= 1;
                            t2.second -= 1;
                            if (t2 == jiang) continue;
                            t2.first -= 1;
                            t2.second -= 1;
                            if (check(t2) == false) continue;
                            // 到达新位置
                            if (mp.count(t2) == 0) {
                                mp[t2] = mp[t] + 1;
                                q.emplace(t2);
                            }
                        }
                        if (k == 1) { // right
                            pair<int, int> t2(t1);
                            t2.first += 1;
                            t2.second -= 1;
                            if (t2 == jiang) continue;
                            t2.first += 1;
                            t2.second -= 1;
                            if (check(t2) == false) continue;
                            // 到达新位置
                            if (mp.count(t2) == 0) {
                                mp[t2] = mp[t] + 1;
                                q.emplace(t2);
                            }
                        }
                    }
                }
                if (d1 == 3) { // left
                    for (int k = 0; k < 2; k++) {
                        if (k == 0) { // top
                            pair<int, int> t2(t1);
                            t2.first -= 1;
                            t2.second += 1;
                            if (t2 == jiang) continue;
                            t2.first -= 1;
                            t2.second += 1;
                            if (check(t2) == false) continue;
                            // 到达新位置
                            if (mp.count(t2) == 0) {
                                mp[t2] = mp[t] + 1;
                                q.emplace(t2);
                            }
                        }
                        if (k == 1) { // down
                            pair<int, int> t2(t1);
                            t2.first -= 1;
                            t2.second -= 1;
                            if (t2 == jiang) continue;
                            t2.first -= 1;
                            t2.second -= 1;
                            if (check(t2) == false) continue;
                            // 到达新位置
                            if (mp.count(t2) == 0) {
                                mp[t2] = mp[t] + 1;
                                q.emplace(t2);
                            }
                        }
                    }
                }
            }
        }
    }
    if (mp.count(jiang) == 0) {
        cout << -1;
    } else {
        cout << mp[jiang];
    }
    return 0;
}
