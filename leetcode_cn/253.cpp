#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> occupied;
        for (vector<int> &x : intervals) {
            if (!occupied.empty() && occupied.top() <= x[0]) { occupied.pop(); }
            occupied.emplace(x[1]);
        }
        return occupied.size();
    }
};
int main() {
    //
    return 0;
}