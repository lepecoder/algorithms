#include <algorithm>
#include <iostream>

using namespace std;

int backtrace(int arr[], int n, int m, int k, int nengque, int step) {
    if (m <= 0) { return step - 1; }
    if (step == n) { return step; }
    int step1 = backtrace(arr, n, m - arr[step], k, nengque - 1, step + 1);
    int step2 = -1;
    if (nengque <= 0) { step2 = backtrace(arr, n, m, k, k, step + 1); }
    return max(step1, step2);
}

int main() {
    int _IO = []() {
        std::ios::sync_with_stdio(0);
        cin.tie(0); // cout.tie(0);
        return 0;
    }();
    int n, m, k;
    cin >> n >> m >> k;
    int arr[1000];
    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    cout << backtrace(arr, n, m, k, 0, 0);

    return 0;
}
