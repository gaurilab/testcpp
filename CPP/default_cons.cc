#include <iostream>

class X {
 public:
  int x ;
  int y;
  //X():x(0),y(0){}
};
using namespace std;
int main()
{
    X xx;
    cout<<xx.x<<xx.y<<endl;
    return 0;
}
