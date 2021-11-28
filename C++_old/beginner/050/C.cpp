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
static const int MAX=100000;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int N,l;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>l; mp[l]++;
    }
    bool flag=true;
    if(N&1){
        if(mp[0]!=1)flag=false;
        for(int i=1;2*i+1<=N;i++){
            if(mp[2*i]!=2)flag=false;
        }
        
    }else{
        for(int i=0;2*i+1<=N;i++){
            if(mp[2*i+1]!=2)flag=false;
        }
    }
    if(!flag){
        cout<<0<<"\n";
        return 0;
    }
    ll ans=1;
    if(N&1){
        for(int i=0;i<(N-1)/2;i++)ans=(ans*2)%MOD;
    }else{
        for(int i=0;i<N/2;i++)ans=(ans*2)%MOD;
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
