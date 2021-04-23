#include <iostream>

using namespace std;

int main(void) {
    const int a = 7;
    int *p = (int *)&a;
    *p = 8;
    cout << a;
    system("pause");
    return 0;
}