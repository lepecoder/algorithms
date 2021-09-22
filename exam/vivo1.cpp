#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    vector<int> calculateUserList(vector<int> &userIdList, vector<double> &costList, vector<double> &conversionList, double k) {
        int n = userIdList.size();
        vector<pair<double, int>> cost_k(n, pair<double, int>());
        for (int i = 0; i < n; i++) {
            cost_k[i].first = costList[i] / conversionList[i];
            cost_k[i].second = i;
        }
        sort(cost_k.begin(), cost_k.end());
        for (int i = 0; i < n; i++) { cout << cost_k[i].second << ',' << cost_k[i].first << endl; }
        vector<int> res;
        res.reserve(n);
        double cost = costList[cost_k[0].second];
        double userNums = conversionList[cost_k[0].second];
        for (int i = 1; i < n; i++) {
            if ((cost / userNums) > k) { break; }
            res.emplace_back(userIdList[cost_k[i - 1].second]);
            cost += costList[cost_k[i].second];
            userNums += conversionList[cost_k[i].second];
        }
        sort(res.begin(), res.end());
        return res;
    }
};
int main() {
    //
    return 0;
}