
#include <iostream>
using namespace std;
int fun1(int tmp1, int tmp2) { return tmp1 * tmp2; }
int fun2(int tmp1, int tmp2) { return tmp1 / tmp2; }

int main() {
    int (*fun)(int, int);
    fun = fun1;
    cout << fun(15, 5) << endl;
    fun = fun2;
    cout << fun(15, 5) << endl;
    return 0;
}