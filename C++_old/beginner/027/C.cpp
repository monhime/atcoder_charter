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
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
ll N;
//2^n<=N<2^(n+1)となるnを求める
int root2(ll N){
    ll x=1;
    int cunt=0;
    while(x<=N){x*=2;cunt++;}
    return --cunt;
}
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N;

    int n=root2(N);
    if(!(n%2)){
        ll x=1ll;
        for(int i=0;i<n/2;i++) x=4*x+2;
        if(N<x)cout<<"Takahashi"<<"\n";
        else cout<<"Aoki"<<"\n";
    }
    else{
        ll x=2;
        for(int i=0;i<n/2;i++) x=4*x+2;
        if(N<x) cout<<"Aoki"<<"\n";
        else cout<<"Takahashi"<<"\n";
    }
        
    
    return 0;
}
