#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int n,A[22];

bool solve(int i,int m){
    if(m==0)return 1;
    if(i>=n)return 0;
    bool res=solve(i+1,m)||solve(i+1,m-A[i]);
    return res;
}
int main(){
    int q,M;
    cin>>n;
    for(int i=0;i<n;i++)cin>>A[i];
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>M;
        if(solve(0,M))cout<<"yes"<<"\n";
        else cout<<"no"<<"\n";
    }
    return 0;
}

