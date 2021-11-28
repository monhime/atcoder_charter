#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<deque>
//#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
vector<int> V;
list<int> L;
stack<int> S;
queue<int> Q;
deque<int> dq;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=50;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
ll sum=-INFLL;
int N,a[MAX+1],aa[MAX+1];

ll solve(int i){
    ll aoki=-INFLL,taka;
    for(int j=1;j<=N;j++){
        if(i==j) continue;
        int l=min(i,j);
        int r=max(i,j);
        
        ll aa=0,tt=0;
        for(int k=l;k<=r;k++){
            if((k-l)&1) aa+=a[k];
            else tt += a[k];
        }
        
        if(aoki<aa){
            aoki=aa;
            taka=tt;
        }
    }
    return taka;
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N;
    
    for(int i=1;i<=N;i++) cin>>a[i];
    
    for(int i=1;i<=N;i++) sum =max(sum,solve(i));
    
    cout<<sum<<"\n";
    
    return 0;
}
