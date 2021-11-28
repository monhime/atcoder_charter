#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    int A[N],B[N+1];
    int MAX=0;
    cin>>A[0];
    B[0]=A[0];
    MAX+=abs(B[0]);
    for(int i=1;i<N;i++){
        cin>>A[i];
        B[i]=A[i]-A[i-1];
        MAX+=abs(B[i]);
    }
    B[N]=-A[N-1];
    MAX+=abs(B[N]);
    for(int i=0;i<N;i++){
        if(B[i]*B[i+1]<0){
            cout<<MAX-2*min(abs(B[i]),abs(B[i+1]))<<"\n";
        }
        else 
            cout<<MAX<<"\n";
    }
    return 0;

}

