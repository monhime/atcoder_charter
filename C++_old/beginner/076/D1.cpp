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
static const int MAX=100;
int v[MAX+2],t[MAX+2],N,t_sum[MAX*2+4],min_v[2*MAX+4];;
double ans,right1,left1;
void solve(){
    min_v[0]=0;
    min_v[2*N]=0;
    for(int x=1;x<=MAX*2+4;x++){
        int i;
        for( i=1;t[i]<x;i++){
            if(min_v[x]>v[i]+x/2-t[i])
                min_v[x]=v[i]+x/2-t[i];
        }
        i++;
        if(min_v[x]>v[i])min_v[x]=v[i];
        i++;
        for(;i<=2*MAX+4;i++){
            if(min_v[x]>v[i]+t[i]-x/2)
                min_v[x]=v[i]+t[i]-x/2;
        }
    }
    for(int x=1;x<=2*MAX+4;x++){
        ans+=(double)(min_v[x-1]+min_v[x])/4;
        cout<<ans<<" ";
    }
}
int main(){
    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>t[i];
        t[i]+=t[i-1];    
    }
    v[0]=0;
    v[N+1]=0;
    for(int i=1;i<=N;i++){
        cin>>v[i];
    }

    solve();
    printf("%.15f\n",ans);
    return 0;
}


