#include <set>
#include <iostream>

static int guid[]={1,2,3,4,5,6};
std::set<int> x(guid,guid+sizeof(guid)/sizeof(int));
int main() {
    for (std::set<int>::iterator it = x.begin(); it != x.end() ; ++it) {
        std::cout<<*it<<std::endl;
    }
    return 0;
}
