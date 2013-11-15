#include <iostream>
#include <map>


using namespace std;

class key{
    public:
        string s1;
        string s2;
        string s3;
        key(string S1="",string S2="", string S3=""):s1(S1),s2(S2),s3(S3){}
        key(const key& In):s1(In.s1),s2(In.s2),s3(In.s3){}

        friend  bool operator<(const key& k1,const key& k2){
             if(k1.s1 < k2.s1) return true;
             if((k1.s1 == k2.s1)&&(k1.s2 < k2.s2)) return true;
             if((k1.s1 == k2.s1)&&(k1.s2 == k2.s2) && (k1.s3 < k2.s3)) return true;
             return false;
        }
        friend  bool operator>(const key& k1,const key& k2){
             if(k1.s1 > k2.s1) return true;
             if((k1.s1 == k2.s1)&&(k1.s2 > k2.s2)) return true;
             if((k1.s1 == k2.s1)&&(k1.s2 == k2.s2) && (k1.s3 > k2.s3)) return true;
             return false;
        }

        friend  bool operator==(const key& k1,const key& k2){
             if((k1.s1 == k2.s1)&& (k1.s2 == k2.s2)&& (k1.s2 == k2.s2))
                return true;
             return false;
        }
        friend ostream&  operator<<(ostream& out, const key &k){
             out<<k.s1<<"-"<<k.s2<<"-"<<k.s3;
             return out;
        }
};


typedef map <key,string>  List;
typedef map <key,string>::iterator  ListIt;

int main(){
    key k("a","b","c");
    List l;
    l.insert(make_pair(k,"This is a test string"));
    k.s2="c";
    l.insert(make_pair(k,"This is a test string"));
    k.s2="d";
    l.insert(make_pair(k,"This is a test string"));
    k.s2="e";
    l.insert(make_pair(k,"This is a test string"));
    k.s2="f";
    l.insert(make_pair(k,"This is a test string"));

    for(ListIt it= l.begin(); it !=l.end();it++){
        cout<<it->first<<"-->"<<it->second<<endl;
   }
    return 0;
}
