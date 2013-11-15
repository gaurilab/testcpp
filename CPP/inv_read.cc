
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
typedef vector<int> vi;

int merge_and_count(const vi& A , const vi& B, vi &C );
#define PRINT if(0)printf
#define COUT  if(0)cout
long count_inversions(vi &input){
    if(input.size() == 0 || input.size() == 1 )return 0;

    int  mid = input.size()/2;
    //Divide
    vi result(input.size(),0);
    vi left(input.begin(),input.begin()+mid);
    vi right(input.begin()+mid ,input.end() );
    COUT<<endl;
    int t=0;
    for(vi::iterator it = left.begin(); it!= left.end(); ++it){
        PRINT(" left[%d]=%d\t",t++,*it);
    }
    COUT<<endl;
   
    long res1  = count_inversions(left);
    long res2  = count_inversions(right);
     t=0;
    for(vi::iterator it = right.begin(); it!= right.end(); ++it){
        PRINT("right[%d]=%d\t",t++,*it);
    }
    COUT<<endl;

    long res3  = merge_and_count(left,right,result);
    long res =res1 + res2 + res3;
    
    t=0;
    for(vi::iterator it = result.begin(); it!= result.end(); ++it){
        PRINT("result[%d]=%d\t",t++,*it);
    }

    input = result;

    COUT<<endl;
    return res;
}

int  merge_and_count(const vi& A , const vi& B, vi &C ){
    size_t k =0 ;
    size_t i =0 , j=0 ; 
    int num_inversions = 0;
    for( ;i < A.size() &&  j < B.size();){
        if(A[i]<B[j])
        C[k++] =  A[i++];
        else{
        C[k++] =  B[j++];
        num_inversions += A.size() - i;
        assert(num_inversions>0);
        }
    }
    while(i < A.size()){
        C[k++] =  A[i++];
    }
    while(j< B.size()){
        C[k++] =  B[j++];
    }
    
    int t=0;
    COUT<<endl;
    for(vi::iterator it = C.begin(); it!= C.end(); ++it){
        PRINT("C[%d]=%d\t",t++,*it);
    }
    COUT<<endl;
  return num_inversions;
}
int main(int argc , char* argv[]){

    vi input;
    const char* filename = "ntegerArray.txt";
    std::ifstream inFile(filename);

  // Make sure the file stream is good
  if(!inFile) {
    COUT << endl << "Failed to open file " << filename;
    return 1;
  }

  int n = -1;
  while(!inFile.eof()) {
    inFile >> n;
    if (n!= -1)
    input.push_back(n);
    n = -1;
  }
    int k=0;
    for(vi::iterator it = input.begin(); it!= input.end(); ++it){
        PRINT("\n input[%d] = %d",k++,*it);
    }
    
    COUT<<endl;
    printf("\n\n\n nuber of inversions = %lu ",count_inversions(input));
    COUT<<endl;
    k=0;
    for(vi::iterator it = input.begin(); it!= input.end(); ++it){
        PRINT("\n input[%d] = %d",k++,*it);
    }
    COUT<<endl;
    return 0;
}

