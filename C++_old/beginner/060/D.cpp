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
#include<sstream>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
#define INF (1<<29) //53687091
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e9;
static const int MOD=1e9+7;
static const int NMAX=100;
static const int VMAX=1e7;
int n;
ll W,w[NMAX+2],v[NMAX+2];

void solve(){
    ll ans=0;
    map<ll,ll> dp;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        auto tmp=dp;
        for(auto p:tmp){
            auto x=p.first+w[i];
            auto y=p.second+v[i];
            if(x<=W){
                dp[x]=max(dp[x],y);
                ans=max(ans,dp[x]);
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    cin>>n>>W;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    solve();
    return 0;
}
