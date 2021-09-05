#include <bits/extc++.h>
using namespace std;

class E {
  public:
    E() { cout << "E\n"; }
    ~E() { cout << "~E\n"; }
};
class D {
  public:
    D() { cout << "D\n"; }
    ~D() { cout << "~D\n"; }
};

class A {
  public:
    A() { cout << "A\n"; }
    virtual ~A() { cout << "~A\n"; }

    //   private:
    // E d;
};

class B : public A {
  public:
    B() { cout << "B\n"; }
    ~B() { cout << "~B\n"; }

  private:
    A a;
};

class C : public A, public B {
  public:
    C() { cout << "C\n"; }
    ~C() { cout << "~C\n"; }

  private:
    D a;
};

int main() {
    //
    C *p = new C;
    delete p;
    // A *a = new A;
    return 0;
}
