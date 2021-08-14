#include <bits/stdc++.h>
using namespace std;
int *t;
void fun() {
    for (int i = 0; i < 5; i++) { cout << t[i] << ' '; }
}
int main() {
    //
    // CSomething x;
    // int i = 0;
    int a[5] = {3, 2, 1, 5, 4};
    t = a;
    fun();
    return 0;
}