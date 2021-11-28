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
int v[MAX+2],t[MAX+2],N;
double ans;
void solve(){
    for(int i=1;i<=N;i++){
        if(v[i]>=v[i-1]){
            double t1=(double)(v[i+1]-v[i-1]+t[i])/2;
            if(v[i+1]>=v[i]){
                ans+=(double)v[i]*t[i]
                    -(double)(v[i]-v[i-1])*(v[i]-v[i-1])/2;
            }else if(v[i-1]+t1<v[i]){
                ans+=(v[i-1]*2+t1)*t1/2
                    +(v[i-1]+v[i+1]+t1)*(t[i]-t1)/2;
            }else{
                ans+=v[i]*t[i]
                    -(double)(v[i]-v[i-1])*(v[i]-v[i-1])/2
                    -(double)(v[i]-v[i+1])*(v[i]-v[i+1])/2;
            }
        }else{
            if(v[i+1]-v[i]<0){
                ans+=(double)t[i]*v[i]
                    -(double)(v[i+1]-v[i])*(v[i+1]-v[i])/2;
            }else{
                ans+=t[i]*v[i];
            }
        }
    }    
}
int main(){
    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>t[i];
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

