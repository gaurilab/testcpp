#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;
/*
User defined type  shall have default constructor , operators >  , operator== ,operator <  operator<<
For inbuilt types none is required
*/
class empty{
    friend ostream&  operator<<(ostream& out, const empty &k){
            return out;
        }

};

template <typename keyTypeA , typename keyTypeB ,typename keyTypeC>
class CompositeKey {
    public:
        CompositeKey (keyTypeA aa = keyTypeA(),
                keyTypeB bb =keyTypeB() ,
                keyTypeC cc=keyTypeC()): keyA(aa), keyB(bb), keyC(cc){}

        CompositeKey(const CompositeKey & M):keyA(M.keyA),keyB(M.keyB),keyC(M.keyC){}
        friend  string to_string(const CompositeKey &k);

    private:
        keyTypeA keyA;
        keyTypeB keyB;
        keyTypeC keyC;

};

template <typename keyTypeA , typename keyTypeB ,typename keyTypeC>
friend  string to_string<keyTypeA,keyTypeB,keyTypeC>(const CompositeKey &k){
    ostringstream out;
    out<< k.keyA<< "-" << k.keyB << "-" << k.keyC;
    return out.str();
}

friend  bool operator<(const CompositeKey & k1,const CompositeKey & k2){
    if(k1.keyA < k2.keyA) return true;
    if((k1.keyA == k2.keyA)&&(k1.keyC < k2.keyC)) return true;
    if((k1.keyA == k2.keyA)&&(k1.keyC == k2.keyC) && (k1.keyB < k2.keyB)) return true;
    return false;
}

friend  bool operator>(const CompositeKey & k1,const CompositeKey & k2){
    if(k1.keyA > k2.keyA) return true;
    if((k1.keyA == k2.keyA)&&(k1.keyC > k2.keyC)) return true;
    if((k1.keyA == k2.keyA)&&(k1.keyC == k2.keyC) && (k1.keyB > k2.keyB)) return true;
    return false;
}

    friend  bool operator==(const CompositeKey & k1,const CompositeKey & k2){
        if((k1.keyA == k2.keyA)&& (k1.keyC == k2.keyC)&& (k1.keyC == k2.keyC))
            return true;
        return false;
    }
friend ostream&  operator<<(ostream& out, const CompositeKey &k){
    out<<k.keyA<<"-"<<k.keyB<<"-"<<k.keyC;
    return out;
}


typedef CompositeKey<string,string,string> allStringKeyT;
typedef CompositeKey<string,int,string> twoStringKeyT;
typedef CompositeKey<string,int,empty> userDefinedT;

int main()
{
    allStringKeyT k0;
    cout<<k0<<endl;
#if 1
    allStringKeyT k1("a","b","c");
    allStringKeyT k2("a","b","d");
    allStringKeyT k3("f","b","c");
    allStringKeyT k4("a","c");
    cout<<k1<<endl;
    cout<<k2<<endl;
    cout<<k3<<endl;
    cout<<k4<<endl;
    cout<<to_string(k1)<<endl;
    cout<<(k1 == k1)<<endl;
    cout<<(k1 < k2)<<endl;
    cout<<(k1 < k3)<<endl;
    cout<<(k1 < k4)<<endl;
    cout<<(k1 < k1)<<endl;
    cout<<"===================================="<<endl;
    twoStringKeyT M0;
    cout<<M0<<endl;
    twoStringKeyT M1("a",1,"b");
    cout<<M1<<endl;
    twoStringKeyT M2("a",2);
    cout<<M2<<endl;
    cout<<(M1 == M2)<<endl;
    cout<<(M1 > M2)<<endl;
    cout<<(M1 < M2)<<endl;
    twoStringKeyT M3("a",1);
    cout<<(M1 == M3)<<endl;
    twoStringKeyT M4;
    twoStringKeyT M5;
    cout<<"======= User Defined ============================="<<endl;
    userDefinedT S1;
    userDefinedT S2("a",1);
    cout<<S1<<endl;
    cout<<S2<<endl;
#endif
        return 0;
}
