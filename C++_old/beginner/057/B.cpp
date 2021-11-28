    
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
//#include <bits/stdc++.h>
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
using namespace std;
map <int,int> mp;
typedef long long ll;
typedef pair<ll,ll> P;
static const int MAX=100000;
static const int NMAX=50;
int N,M;
vector <P> a(NMAX),c(NMAX);
vector<int> d(NMAX),ans(NMAX);;
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++)cin>>a[i].first>>a[i].second;
    for(int i=0;i<M;i++)cin>>c[i].first>>c[i].second;

    for(int i=0;i<N;i++)d[i]=INF;
        
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int dis=abs(c[j].first-a[i].first)+
                    abs(c[j].second-a[i].second);
            if(d[i]>dis){
                d[i]=dis;
                ans[i]=j;
            }
        }
    }
    for(int i=0;i<N;i++)cout<<ans[i]+1<<"\n";
    return 0;
}

