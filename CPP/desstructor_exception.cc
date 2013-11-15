#include <iostream>
using namespace std;

struct E {
  const char* message;
  E(const char* arg) : message(arg) { }
};

void my_terminate() {
  cout << "Call to my_terminate" << endl;
};

struct A {
  A() { cout << "In constructor of A" << endl; }
  ~A() {
    cout << "In destructor of A" << endl;
 //   try {
    throw E("Exception thrown in ~A()");
   // } catch (...) {
   // cout << " Catching the exception thrown from destructor of A" << endl;
  // }
  }
};
void dummy2 (){
   cout << "In "<<__func__<<" Just like taht" << endl;
}
void dummy1 (int x ){
   int a; int b;
   cout << "In "<<__func__<<" Just like taht" <<x<< endl;
   dummy2();
}

struct B {
  B() { cout << "In constructor of B" << endl; }
  ~B() { cout << "In destructor of B" << endl; }
};

int main(){
    set_terminate(my_terminate);
    try {
        cout << "In try block" << endl;
        A a;

        B b;
       dummy1(4);
        throw("Exception thrown in try block of main()");
    }
    catch (const char* e) {
        cout << "Exception: " << e << endl;
    }
    catch (...) {
        cout << "Some exception caught in main()" << endl;
    }

    cout << "Resume execution of main()" << endl;
}
