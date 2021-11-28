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
ll N,M,t,cunt,aa,bb;
ll X,Y;
vector<ll> a,b;

void solve(){
    while(1){
        auto it_a=lower_bound(a.begin(),a.end(),t);
        if(it_a==a.end())break;
        t=*it_a+X;

        auto it_b=lower_bound(b.begin(),b.end(),t);
        if(it_b==b.end())break;
        t=*it_b+Y;
        cunt++;
    }
}
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>M>>X>>Y;
    

    for(ll i=0ll;i<N;i++) {cin>>aa; a.push_back(aa);}
    for(ll i=0ll;i<M;i++) {cin>>bb; b.push_back(bb);}
    
    solve();
    
    cout<<cunt<<"\n";
    
    return 0;
}
