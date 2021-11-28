#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
//#include <bits/stdc++.h>
using namespace std;
static const int MAX=100000;
int s[MAX],t[MAX],c[MAX];
int sum[2*MAX+1],tt[2*MAX+1];
int N,C,max_sum;

void solve(){
    for(int i=1;i<=C;i++){
        for(int j=0;j<2*MAX+1;j++)tt[j]=0;
        for(int j=0;j<N;j++){
            if(c[j]==i){
                tt[s[j]*2-1]++;
                tt[t[j]*2]--;
            }
        }
        for(int j=1;j<=MAX*2;j++){
            tt[j]+=tt[j-1];
        }    
        for(int j=0;j<=MAX*2;j++){
            if(tt[j]>0)sum[j]++;
        }    
    }

    for(int i=0;i<MAX*2;i++){
        if(max_sum<sum[i])max_sum=sum[i];
    }
}
int main(){
    cin>>N>>C;
    for(int i=0;i<N;i++)
        cin>>s[i]>>t[i]>>c[i];
    solve();
    cout<<max_sum<<"\n";
    return 0;
}

