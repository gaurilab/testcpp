
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int merge_and_count(const vi& A , const vi& B, vi &C );

int count_inversions(vi input){
    if(input.size() == 0 || input.size() == 1 )return 0;

    int  mid = input.size()/2;
    //Divide
    vi result(input.size(),0);
    vi left(input.begin(),input.begin()+mid);
    vi right(input.begin()+mid ,input.end() );
    return (count_inversions(left)+
    count_inversions(right) +
    merge_and_count(left,right,result));
}
int merge_and_count(const vi& A , const vi& B, vi &C ){
    size_t k =0 ;
    size_t i =0 , j=0 ; 
    int num_inversions = 0;
    for( ;i < A.size() &&  j < B.size();){
        if(A[i]<B[j])
        C[k++] =  A[i++];
        else{
        C[k++] =  B[j++];
        num_inversions = A.size() - k + 1;
        }
    }
    while(i< A.size()){
        C[k++] =  A[i++];
    }
    while(j< B.size()){
        C[k++] =  B[j++];
    }
    
  return num_inversions;
}
int main(int argc , char* argv[]){

    vi input;
    printf("%d",input.size());
    for(int k = 1; k < argc  ; ++k){
    input.push_back(atoi(argv[k]));
    }

    int k =0;
    for(vi::iterator it = input.begin(); it!= input.end(); ++it){
        printf("\n input[%d] = %d",k++,*it);
    }
    printf("\n\n\n nuber of inversions = %d ",count_inversions(input));
    return 0;
}

