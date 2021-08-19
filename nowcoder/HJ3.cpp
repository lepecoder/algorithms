#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, t;
    set<int> st;
    while (cin >> n) {
        while (n--) {
            cin >> t;
            st.emplace(t);
        }
        for (const int &x : st) { cout << x << endl; }
        st.clear();
    }
    return 0;
}
