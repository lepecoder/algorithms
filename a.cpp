#include <iostream>

using namespace std;
class cl {
  public:
    int y = 1;
    static const auto z{123};
    int x;
};
int main(void) {
    int a = 13;
    while (cin >> a) { cout << a << endl; }
    cout << "end\n";

    return 0;
}