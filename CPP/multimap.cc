#include <iostream>
#include <map>

using namespace std;

int main(){
    typedef std::map<uint32_t, string> inner_map_t;
    typedef std::map<std::string,inner_map_t > outer_map_t ;
    outer_map_t OMap;
    outer_map_t::iterator O_it;
    inner_map_t::iterator I_it;
    {
    inner_map_t x;
    //x.insert(make_pair(1,"Value11"));
    OMap.insert(make_pair("Key1",x));
    printf("\n Local %p",&x);
    }
    
    O_it = OMap.find("Key1");
    printf("\nMap: %p",&O_it->second);
    O_it->second.insert(make_pair(1,"Value11"));   
    O_it->second.insert(make_pair(1,"Value12"));   
    O_it->second.insert(make_pair(3,"Value13"));   
    O_it->second.insert(make_pair(4,"Value14"));   
    O_it->second.insert(make_pair(5,"Value15"));   
    /*OMap["Key1"][1]="Value1";
    OMap["Key1"][2]="Value2";
    OMap["Key2"][1]="Value3";
    OMap["Key2"][2]="Value4";
    OMap["Key3"][2]="Value5";
    */
    for(O_it = OMap.begin(); O_it != OMap.end(); O_it++){
       for(I_it = O_it->second.begin(); I_it != O_it->second.end(); I_it++){
       printf("\n Key = [%s] First = %d , Second = [%s]",O_it->first.c_str(),I_it->first, I_it->second.c_str());       
       }
    } 
    printf("\n");
    return 0;
}
