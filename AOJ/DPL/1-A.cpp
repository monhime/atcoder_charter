#include<iostream>
#include<algorithm>
#include<math.h>
#include<float.h>
#include<cstdio>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
static const int MMAX=20;
static const int NMAX=500000;
static const int INFTY=2000000000;
int main(){
    int n,m;
    int C[MMAX+1],T[NMAX+1];
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>C[i];
    for(int i=0;i<NMAX;i++) T[i]=INFTY;
    T[0]=0;
    for(int i=1;i<=m;i++){
        for(int j=C[i];j<=n;j++)
            T[j]=min(T[j],T[j-C[i]]+1);
    }
    cout<<T[n]<<"\n";
    return 0;
}
