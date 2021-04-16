#include <bits/stdc++.h>
using namespace std;
class cl {
  public:
    int a = 1;
    vector<cl *> c;
    cl() : c(22) {}
};
class cr {
  public:
    int a;
    static vector<cl *> c(21);
};
int main() {
    vector<cl *> t(2);
    cout << (t[0] == nullptr);
    return 0;
}