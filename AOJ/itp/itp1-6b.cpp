#include<iostream>
using namespace std;

void print(int A[],char a){
    for(int i=1;i<14;i++){
        if(A[i]==0)cout<<a<<" "<<i<<"\n";
    }
}

int main(){
    int n,tmp;
    char mark;
    int S[14],H[14],C[14],D[14];

    for(int i=1;i<14;i++)S[i]=H[i]=C[i]=D[i]=0;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>mark>>tmp;  
      switch(mark){
        case 'S':
            S[tmp]=1;
            break;
        case 'H':
            H[tmp]=1;
            break;
        case 'C':
            C[tmp]=1;
            break;
        case 'D':
            D[tmp]=1;
            break;
            
      }

    }
    print(S,'S');
    print(H,'H');
    print(C,'C');
    print(D,'D');
    return 0;
    
}
