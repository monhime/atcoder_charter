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
vector<int> V;
#define INF (1<<29)
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N,M;
ll maxn=-INFLL,a[MAX+2][3];

void solve(){
    for(int i=0;i<8;i++){
        vector<ll> vec;
        for(int j=0;j<N;j++){
            ll S=0;
            for(int k=0;k<3;k++){
                if((i>>k)&1) S+=a[j][k];
                else S-=a[j][k];
            }
            vec.push_back(S);
        }
        sort(vec.begin(),vec.end(),greater<ll>());
        ll ans = 0;
        for(int j=0;j<M;j++) ans += vec[j];
        maxn = max(maxn,ans);
    }
    cout<<maxn<<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++) cin>>a[i][j];
    }
    solve();
    
    return 0;
}

