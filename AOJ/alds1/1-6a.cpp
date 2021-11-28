#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 2000001
#define VMAX 10000
int main(){ 
    unsigned short *A,*B;

    int C[VMAX+1];
    int n,i,j;
    cin>>n;

    A=(unsigned short*)malloc(sizeof(unsigned short)*n);
    B=(unsigned short*)malloc(sizeof(unsigned short)*n);

    for(i=0;i<=VMAX;i++)C[i]=0;
        
    for(i=0;i<n;i++){
        cin>>A[i];
        C[A[i]]++;
    }
    for(i=0;i<VMAX;i++)C[i+1]=C[i+1]+C[i];

    for(i=0;i<n;i++){
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }
    for(i=0;i<n;i++){
        cout<<(i?" ":"")<<B[i];
    }
    cout<<"\n";
    return 0;

}

