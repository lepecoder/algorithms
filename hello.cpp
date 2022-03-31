#include <iostream>
using namespace std;
#define ll long long
void fun(int &a) {
    a = 123;
}
class Cls
{
public:
    void fun() {
        cout << 12;
    }
    void emp() {
    }
    void fun1() {
        if (true) {
            cout << 1;
        }
        else {
            cout << 2;
        }
    }
};
int main() {
    //
    int a = 1;
    fun(a);
    cout << "hello";
    cout << a;
    return 0;
}