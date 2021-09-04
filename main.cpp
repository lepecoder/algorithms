#include <bits/stdc++.h>
using namespace std;
class A {
    bool a;   // 1字节
    short b;  // 2字节，+1
    int c;    // 4字节，
    double d; // 8字节
};
int main() {
    A a;
    cout << sizeof(a) << endl;
    return 0;
}