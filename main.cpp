#include <bits/stdc++.h>
using namespace std;

class BaseClass {
  public:
    void f1() { cout << "base class f1()\n"; }
    virtual void f2() { cout << "base class virtual f2()\n"; }
};

class DerivedClass : public BaseClass {
  public:
    void f1() { cout << "derived class f1()\n"; }
    void f2() override { cout << "derived class f2()\n"; }
};

int main() {
    //
    // CSomething x;
    // int i = 0;
    BaseClass *p = new DerivedClass();
    p->f1();
    p->f2();

    return 0;
}