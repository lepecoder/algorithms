#include <bits/stdc++.h>
using namespace std;
int main() {
    string line;
    int num;
    vector<int> nums;
    while (getline(cin, line)) {
        nums.clear();
        istringstream stream(line);
        while (stream >> num) { nums.emplace_back(num); }
        for (int &x : nums) { cout << x << ' '; }
        cout << endl;
    }

    return 0;
}