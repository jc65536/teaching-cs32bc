#include <iostream>
using namespace std;

struct A {
    long long u;

    A(long long u) : u(u) {
    }

    virtual void f() {
        cout << "A::f" << endl;
    }

    virtual void g(int i) {
        cout << "A::g i = " << i << endl;
    }
};

struct B : A {
     
    B(long long u, long long v) : A(u), v(v) {
    }

private:
    long long v;

    void f() override {
        cout << "B::f" << endl;
    }

    void g(int i) override {
        cout << "B::g i = " << i << " u = " << this->u << endl;
    }
};

int main() {
    B b(1234, 5678);

    sizeof(b);

    long long *p = (long long *) &b;

    // p[0][0]
    void (*f)(B *) = ((void (***)(B*)) p)[0][0];

    void (*g)(B *, int) = ((void (***)(B*, int)) p)[0][1];

    // cout << ((long long *) p[0])[0] << endl;
    f(nullptr);
    g(&b, 5);
    cout << p[1] << endl;
    cout << p[2] << endl;
}
