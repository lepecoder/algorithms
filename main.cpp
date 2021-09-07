#include <bits/stdc++.h>
using namespace std;
void fun(int a[3]) { cout << sizeof(a) << endl; }
int main() {
    //
    int a[] = {1, 22, 3};
    cout << sizeof(a) << endl;
    fun(a);
    // int *p = a;
    // cout << sizeof(p) << endl;
    // char str[] = "1123";
    // cout << sizeof(str) << endl;
    // a++;
    return 0;
}