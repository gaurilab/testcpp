#include<iostream>
using namespace std;
class A {
public:
        A(){}
        A(const A&){cout<<__func__<<endl;}
};

class B {
public:
        B() {}
        B(const B&){cout<<__func__<<endl;}
};

class x {
        public:
        A xx;
        B yy;
        x(A a,B b):xx(a),yy(b){cout<<__func__<<endl;}
};
int main() {
        A aa;
        B bb;
        x N(aa,bb);
        x M=N;
        return 0;
}
