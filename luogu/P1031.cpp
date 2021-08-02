#include <iostream>
using namespace std;

int main() {
    // IO
    int _IO = []() {
        std::ios::sync_with_stdio(0);
        cin.tie(0); // cout.tie(0);
        return 0;
    }();
    int n;
    cin >> n;
    int cards[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        sum += cards[i];
    }
    int average = sum / n;
    for (int i = 0; i < n; i++) { cards[i] -= average; }
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        if (cards[i] != 0) {
            cards[i + 1] += cards[i];
            res++;
        }
    }
    cout << res;

    return 0;
}